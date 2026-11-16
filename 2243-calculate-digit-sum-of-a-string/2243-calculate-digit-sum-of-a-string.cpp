class Solution {
public:
    string digitSum(string s, int k) {
        while ((int)s.length() > k) {
            string result;
            for (int i = 0; i < (int)s.length(); i += k) {
                int sum = 0;
                int end = min(i + k, (int)s.length());
                for (int j = i; j < end; j++) {
                    sum += s[j] - '0';
                }
                result += to_string(sum);
            }
            s = result;
        }
        return s;
    }
};