class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        vector<int>peakValues;
        vector<int>valleyValues;
    int arraySize = static_cast<int>(nums.size());
        for(int index = 1 ; index<arraySize-1;++index){
            if(nums[index]>nums[index-1] && nums[index]>nums[index+1]){
                peakValues.push_back(nums[index]);
            }
        }
        //collect all valley values
        for(int index = 1; index<arraySize-1;++index){
            if(nums[index]<nums[index-1] && nums[index]<nums[index+1]){
                valleyValues.push_back(nums[index]);
            }
        }
        int peakSum = accumulate(peakValues.begin(), peakValues.end(),0);
        int valleySum = accumulate(valleyValues.begin(), valleyValues.end(),0);
        return peakSum - valleySum;
    }
};