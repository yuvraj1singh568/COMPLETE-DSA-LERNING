class Solution {
    int dp[1001][1001];

    int solve(int i, int j, string &s) {

        if (i >= j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;

        if (s[i] == s[j]) {
            ans = solve(i + 1, j - 1, s);
        }
        else {
            int ans1 = 1 + solve(i + 1, j, s);
            int ans2 = 1 + solve(i, j - 1, s);

            ans = min(ans1, ans2);
        }

        return dp[i][j] = ans;
    }

public:
    int minInsertions(string s) {

        memset(dp, -1, sizeof(dp));

        return solve(0, s.size() - 1, s);
    }
};