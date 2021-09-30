test
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0,right = nums.size() - 1;
        unordered_map<int,int> map;
        for (int i=0;i<nums.size();i++){
            map[nums[i]] = i;
        }
        for (int i=0;i<nums.size();i++){
            int other = target - nums[i];
            if (map[other] != 0 && map[other] != i){
                return {i,map[other]};
            }
        }
        return {-1,-1};
    }
};