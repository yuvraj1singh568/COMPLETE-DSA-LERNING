
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2) {
            int sum1 = getDigitSum(num1);
            int sum2 = getDigitSum(num2);

            if (sum1 != sum2) {
                return sum1 < sum2;
            }
            return num1 < num2;
        };

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        unordered_map<int, int> valToIdx;
        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int swapCount = 0;

        for (int i = 0; i < n; i++) {
            int expectedVal = afterSorted[i];
            int curVal = nums[i];

            if (expectedVal == curVal) continue;

            int idx = valToIdx[expectedVal];

            swap(nums[i], nums[idx]);

            valToIdx[expectedVal] = i;
            valToIdx[curVal] = idx;

            swapCount++;
        }

        return swapCount;
    }
};
