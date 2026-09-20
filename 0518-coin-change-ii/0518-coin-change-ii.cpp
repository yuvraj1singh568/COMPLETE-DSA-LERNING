int dp[301][5001];
class Solution {
   
   int f(int idx, int sum , vector<int> &coins, int amount){
    if(idx == coins.size()){
        if(sum==amount){
            return 1;
        }
        return 0;
    }
    if (dp[idx][sum] != -1){
        return dp[idx][sum];
    }
    int ans1 = 0 , ans2 = 0;
     //take
     if(sum+coins[idx] <= amount){
        ans1=f(idx,sum+coins[idx],coins,amount);
     }
     // not take
     ans2 = f(idx+1,sum,coins,amount);
     return   dp[idx][sum]=ans1+ans2;
   }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
          return f(0,0,coins,amount);
                
    }
};