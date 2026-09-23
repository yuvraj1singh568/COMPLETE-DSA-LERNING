class Solution {
    const int BUY = 0;
    const int SELL = 1;

    vector<vector<int>> dp;

    int solve(vector<int>& prices, int idx, int event, int k) {

        if (idx == prices.size() || event == 2 * k)
            return 0;

        if (dp[idx][event] != -1)
            return dp[idx][event];

        // Skip the day
        int ans1 = solve(prices, idx + 1, event, k);

        // Buy or Sell
        int transactionType = event % 2 == 0 ? BUY : SELL;

        int ans2 = 0;

        if (transactionType == BUY) {
            // Buy
            ans2 = -prices[idx] +
                   solve(prices, idx + 1, event + 1, k);
        }
        else {
            // Sell
            ans2 = prices[idx] +
                   solve(prices, idx + 1, event + 1, k);
        }

        return dp[idx][event] = max(ans1, ans2);
    }

public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        dp.assign(n, vector<int>(2 * k, -1));

        return solve(prices, 0, 0, k);
    }
};