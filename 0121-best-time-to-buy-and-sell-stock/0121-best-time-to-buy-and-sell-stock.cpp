const int BUY = 0;
const int SELL = 1;
const int  n=1e5;
int dp[n][2];
class Solution {
    int solve(vector<int>&prices, int idx, int transactionType){
  if(idx == prices.size()) return 0;
  if(dp[idx][transactionType] != -1) return dp[idx][transactionType];
    // skip the day
    int ans1 = solve(prices,idx+1,transactionType);
    //doing the possible trnsaction
    int ans2=0;
    if(transactionType == BUY){
        ans2 = -prices[idx]+ solve( prices,idx + 1, SELL);
    } else{
        ans2= prices[idx];
    }
   return  dp[idx][transactionType] = max(ans1, ans2);
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
     return solve(prices,0,BUY);   
    }
};