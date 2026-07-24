class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int v : nums) {
            auto ndp = dp; // taking this index 0 times

            for (int cnt = 0; cnt <= 3; cnt++) {
                for (int x = 0; x < MAXX; x++) {
                    if (!dp[cnt][x]) continue;

                    for (int t = 1; t + cnt <= 3; t++) {
                        int nx = x;
                        if (t % 2 == 1) nx ^= v; // odd copies contribute v
                        ndp[cnt + t][nx] = true;
                    }
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;
        for (int x = 0; x < MAXX; x++)
            if (dp[3][x]) ans++;

        return ans;
    }
};