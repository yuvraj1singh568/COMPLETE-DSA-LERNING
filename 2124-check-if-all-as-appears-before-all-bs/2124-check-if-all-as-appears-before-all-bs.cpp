class Solution {
public:
    bool checkString(string s) {
        string t=s;
        sort(s.begin(),s.end());
        return t==s;
    }
};