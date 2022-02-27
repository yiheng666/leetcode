class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = INT_MIN,minNum = INT_MAX;
        for (int i=0;i<nums.size();i++){
            minNum = min(minNum,nums[i]);
            if (minNum >= nums[i]) continue;
            res = max(res,nums[i] - minNum);
        }
        return res == INT_MIN ? -1 : res;
    }
};