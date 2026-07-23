class Solution {
public:

    vector<int> leftSmaller(vector<long long> &a) {
        int n = a.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        return left;
    }

    vector<int> rightSmaller(vector<long long> &a) {
        int n = a.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        return right;
    }

    int max_area_histogram(vector<long long>& a, int n) {

        auto left = leftSmaller(a);
        auto right = rightSmaller(a);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long width = right[i] - left[i] - 1;
            ans = max(ans, a[i] * width);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<long long> heights(m, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            // update the heights array
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }

            ans = max(ans, max_area_histogram(heights, m));
        }

        return ans;
    }
};