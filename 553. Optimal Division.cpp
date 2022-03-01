class Solution {
public:
    string optimalDivision(vector<int>& nums) {
         string res;
         int n = nums.size();
         if (n == 2){
             res += to_string(nums[0]) + "/" + to_string(nums[1]);
             return res;
         }
         for (int i=0;i<n;i++){
             if (i == 0) res += to_string(nums[i]);
             else if (i == 1) res += "/(" + to_string(nums[i]);
             else if (i == n-1) res += "/" + to_string(nums[i]) + ")";
             else res += "/" + to_string(nums[i]);
         }
         return res;
    }
};