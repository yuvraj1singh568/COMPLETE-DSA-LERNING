
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int l = points[0][0];
        int r = points[0][1];
        int cnt = 1;

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > r) {
                cnt++;
                l = points[i][0];
                r = points[i][1];
            }
            else {
                l = max(l, points[i][0]);
                r = min(r, points[i][1]);
            }
        }

        return cnt;
    }
};
