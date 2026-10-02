class Solution {
    int dp[1001][1001];

    int solve(string &str1, string &str2, int i, int j) {

        if (i == str1.size()) {
            return str2.size() - j;
        }

        if (j == str2.size()) {
            return str1.size() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;

        if (str1[i] == str2[j]) {
            ans = 1 + solve(str1, str2, i + 1, j + 1);
        }
        else {
            int ans1 = 1 + solve(str1, str2, i + 1, j);
            int ans2 = 1 + solve(str1, str2, i, j + 1);

            ans = min(ans1, ans2);
        }

        return dp[i][j] = ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        memset(dp, -1, sizeof(dp));

        solve(str1, str2, 0, 0);

        string ans = "";

        int i = 0;
        int j = 0;

        while (i < str1.size() && j < str2.size()) {

            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            else {

                int ans1 = solve(str1, str2, i + 1, j);
                int ans2 = solve(str1, str2, i, j + 1);

                if (ans1 <= ans2) {
                    ans += str1[i];
                    i++;
                }
                else {
                    ans += str2[j];
                    j++;
                }
            }
        }

        while (i < str1.size()) {
            ans += str1[i];
            i++;
        }

        while (j < str2.size()) {
            ans += str2[j];
            j++;
        }

        return ans;
    }
};