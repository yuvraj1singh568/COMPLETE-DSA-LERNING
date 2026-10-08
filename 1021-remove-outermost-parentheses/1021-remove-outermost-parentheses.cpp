class Solution {
public:
    string removeOuterParentheses(string& s) {
        int balance=0, j=0;
        for(char c: s){
            balance+=1-((c-'(')<<1);
            s[j]=c;
            j+=!(balance+c-'('==1);
        }
        s.resize(j);
        return s;
    }
};