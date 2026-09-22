const int BUY = 0;
const int SELL = 1;
class Solution {
    int solve(vector<int>&prices, int idx, int transactionType, vector<vector<int>> &dp){
  if(idx == prices.size()) return 0;
  if(dp[idx][transactionType] != -1) return dp[idx][transactionType];
    // skip the day
    int ans1 = solve(prices,idx+1,transactionType,dp);
    //doing the possible trnsaction
    int ans2=0;
    if(transactionType == BUY){
        ans2 = -prices[idx]+ solve( prices,idx + 1, SELL,dp);
    } else{
        ans2= prices[idx];
    }
   return  dp[idx][transactionType] = max(ans1, ans2);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
     return solve(prices,0,BUY,dp);   
    }
};