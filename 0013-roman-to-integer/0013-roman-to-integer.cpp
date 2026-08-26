class Solution {
public:
    int romanToInt(string s) {
        int totalValue = 0;
        int maximumValue = 0;

        for (int index = static_cast<int>(s.size()) - 1; index >= 0; --index) {
            int currentValue = getRomanValue(s[index]);

            if (currentValue < maximumValue) {
                totalValue -= currentValue;
            } else {
                totalValue += currentValue;
                maximumValue = currentValue;
            }
        }

        return totalValue;
    }

private:
    int getRomanValue(char symbol) {
        switch (symbol) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};