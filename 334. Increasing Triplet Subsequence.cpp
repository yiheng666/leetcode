class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(),a = INT_MAX,b = INT_MAX;
        for (int i=0;i<n;i++){
            if (a >= nums[i]) a = nums[i];
            else if (b >= nums[i]) b = nums[i];
            else return true; 
        }
        return false;
    }
};