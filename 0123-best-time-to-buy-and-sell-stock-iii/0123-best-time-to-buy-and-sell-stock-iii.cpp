const int BUY =0;
const int SELL=1;
const int n= 1e5;
int dp[n][4];
 class Solution {
    int solve(vector<int>&prices, int idx , int event){
        if(idx == prices.size() or event ==4) return 0;
        if(dp[idx][event] != -1) return dp[idx][event];
        // skip the day
        int ans1= solve( prices,idx+1,event);
        // doing the possible transaction 
        int transactionType = event % 2 == 0 ? BUY : SELL;
        int ans2=0;
        if(transactionType == BUY){
            ans2 = -prices[idx]+ solve(prices, idx+1, event+1);
        }else{
            ans2= +prices[idx] + solve(prices, idx+1, event+1);
        }
        return dp[idx][event]= max(ans1, ans2);
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(prices,0,0);
    }
};