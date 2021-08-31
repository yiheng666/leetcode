class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0,end = 0,furthest = 0,n = nums.size();
        for (int i=0;i<n-1;i++){
            furthest = max(furthest,nums[i] + i);
            if (end == i){
                jump++;
                end = furthest;
            }
        }
        return jump;
    }
};