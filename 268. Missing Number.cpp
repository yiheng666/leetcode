class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n * (n+1) / 2;
        for (int i : nums){
            res -= i;
        }
        return res;
    }
};