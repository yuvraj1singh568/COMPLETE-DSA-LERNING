class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        std::string numberString = std::to_string(x);
        std::string reversedString = numberString;

        std::reverse(reversedString.begin(), reversedString.end());

        return numberString == reversedString;
    }
};;