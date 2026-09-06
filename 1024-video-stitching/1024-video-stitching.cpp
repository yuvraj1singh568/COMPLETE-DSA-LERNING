class Solution {
public:
    int n;
    int dp[101][101];

    int helper( int i, int prev, vector<vector<int>>& clips, int time){
        //base case

        if(clips[prev][1] >= time) return 0;

        if(i == n) return 1e9;

        if(dp[i][prev] != -1) return dp[i][prev];

        //take
        int take = 1e9;
        if(clips[i][0] <= clips[prev][1]) take = 1 + helper(i+1,i,clips,time);

        //skip
        int not_take = helper(i+1,prev,clips,time);

        return dp[i][prev] = min(take,not_take);
        
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        //1. sorting
        //2. 0-1

        n = clips.size();

        sort(clips.begin(),clips.end());

        memset(dp,-1,sizeof(dp));

        int ans = 1e9;

        for(int i = 0 ; i < n ; i++){
            if(clips[i][0] == 0){
                ans = min(ans,1+helper(i+1,i,clips,time));
            }
        }

        return ans==1e9?-1:ans;

    }
};