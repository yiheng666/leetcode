class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int a = 0,b = 1,pos= 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i] > a) {
                b = a;
                a = nums[i];
                pos = i;
            }
            else if (nums[i] > b){
                b = nums[i];
            }
        }
        if (a >= 2 * b) return pos;
        else return -1;
    }
};