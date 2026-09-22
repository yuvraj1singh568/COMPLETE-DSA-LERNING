class Solution {
     int dp[46];
    int f(int pos, int n){
        if(pos  == n){
            return 1;
        }
        if(pos > n){
            return 0;
        }
        if(dp[pos] != -1){
            return dp[pos];
        }
        //jump of 1 
       int  ans1 = f(pos+1,n);
        // jump of 2
         int ans2 = f(pos+2,n);
        dp[pos]= ans1 + ans2;
        return dp[pos];
    }
public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
       return f(0,n); 
    }
};