class Solution {
public:

    vector<int> leftSmaller(vector<int>& a) {
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

    vector<int> rightSmaller(vector<int>& a) {
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

    int largestRectangleArea(vector<int>& heights) {

        auto left = leftSmaller(heights);
        auto right = rightSmaller(heights);

        long long ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            long long width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }
};