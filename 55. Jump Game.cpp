class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0,n = nums.size();
        for (int i=0;i<n-1;i++){
            furthest = max(furthest,nums[i] + i);
            if (furthest <= i) return false;
        }
        return furthest >= n-1 ;
    }
};