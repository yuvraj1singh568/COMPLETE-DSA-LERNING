const int n=100;
int dp[n];
class Solution {
    int solve(vector<int>&nums,int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx] !=-1)return dp[idx];
        //take
        int ans1=nums[idx]+solve(nums,idx+2);
        //not take
        int ans2= solve(nums,idx+1);
        return  dp[idx]=max(ans1,ans2);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve (nums,0);
    }
};