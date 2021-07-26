class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        int left = 0,right = nums.size()-1,mid,left_bound = 0,right_bound = 0;
        //left_bound
        while (left <= right){
            mid = left + (right - left)/2;
            if (nums[mid] == target){
                right = mid - 1;
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target)
            left_bound = -1;
        else left_bound = left;
        //right_bound
        left = 0,right = nums.size()-1;
        while (left <= right){
            mid = left + (right - left)/2;
            if (nums[mid] == target){
                left = mid + 1;
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
        }
        if (right < 0 || nums[right] != target)
            right_bound = -1;
        else right_bound = right;
        if (left_bound == -1 || right_bound == -1)
            return {-1,-1};
        else return {left_bound,right_bound};
    }
};