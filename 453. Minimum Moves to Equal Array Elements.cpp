class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0,MIN=INT_MAX;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            MIN = min(MIN,nums[i]);
        }
        return sum - MIN * nums.size();
    }
};