
class Solution {
    using ll = long long;
    static const int mod = 1e9 + 7;

    struct node {
        ll lazy = 0;
        ll sumsecond = 0;
        ll sumfirst = 0;

        void set(ll x) {
            lazy = 0;
            sumsecond = x * x % mod;
            sumfirst = x % mod;
        }
    };

    vector<node> t;

    void push(int id, int l, int r) {
        if (t[id].lazy) {
            ll x = t[id].lazy;
            ll len = r - l + 1;

            t[id].sumsecond =
                (t[id].sumsecond
                + 2 * x % mod * t[id].sumfirst % mod
                + x * x % mod * len % mod) % mod;

            t[id].sumfirst =
                (t[id].sumfirst + x * len % mod) % mod;

            if (l != r) {
                t[id << 1].lazy =
                    (t[id << 1].lazy + x) % mod;

                t[id << 1 | 1].lazy =
                    (t[id << 1 | 1].lazy + x) % mod;
            }

            t[id].lazy = 0;
        }
    }

    node merge(node a, node b) {
        node ans;
        ans.sumfirst = (a.sumfirst + b.sumfirst) % mod;
        ans.sumsecond = (a.sumsecond + b.sumsecond) % mod;
        ans.lazy = 0;
        return ans;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            t[id].set(0);
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        t[id] = merge(t[id << 1], t[id << 1 | 1]);
    }

    void update(int id, int l, int r,
                int ql, int qr, ll val) {
        push(id, l, r);

        if (l > qr || r < ql)
            return;

        if (ql <= l && r <= qr) {
            t[id].lazy = (t[id].lazy + val) % mod;
            push(id, l, r);
            return;
        }

        int mid = (l + r) >> 1;

        update(id << 1, l, mid, ql, qr, val);
        update(id << 1 | 1, mid + 1, r, ql, qr, val);

        t[id] = merge(t[id << 1], t[id << 1 | 1]);
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        t.assign(4 * n + 5, node());
        build(1, 0, n - 1);

        unordered_map<int, int> last;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i, 1);

            last[nums[i]] = i;

            ans = (ans + t[1].sumsecond) % mod;
        }

        return (int)ans;
    }
};
