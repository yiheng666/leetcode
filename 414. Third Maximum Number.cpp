class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int change = 0,n = nums.size();
        long max = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if (nums[i] < max){
                max = nums[i];
                change++;
                if (change == 2) {
                    return max;
                }
            }
        }
        return nums[n-1];
    }
};