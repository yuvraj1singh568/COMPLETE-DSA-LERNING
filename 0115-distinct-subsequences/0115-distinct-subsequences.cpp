const  int n = 1e3;
 int dp[n][n];
class Solution {

    int solve(string &s, string &t,int i,int j){
        if( j == t.size()){
            return 1;
        }
        if( i == s.size()){
            return 0;
        }
        if(dp[i][j] != -1){
          return dp[i][j];
        }
        // not take
        int ans1 = solve(s,t,i+1,j);
        // take
        int ans2 = 0;
        if(s[i]==t[j]){
            ans2=solve(s,t,i+1,j+1);
        }
        return dp[i][j] = ans1+ans2;
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof dp);
        return solve(s,t,0,0);
    }
};