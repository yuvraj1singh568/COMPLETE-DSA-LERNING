
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s(n, '#');
        vector<string> v(m, s);

        // Open the entire first row
        for (int j = 0; j < n; j++) {
            v[0][j] = '.';
        }

        // Open the last column
        for (int i = 0; i < m; i++) {
            v[i][n - 1] = '.';
        }

        return v;
    }
};
