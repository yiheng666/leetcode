class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum = 0,minVal = INT_MAX;
        for (int i=0;i<nums.size();i++){
            if (nums[i] < 0 && k > 0){
                k--;
                nums[i] = -nums[i];
            }
            sum += nums[i];
            minVal = min(minVal,nums[i]);
        }
        if (k > 0 && (k & 1)){
            sum -= 2 * minVal;
        }
        return sum;
    }
};