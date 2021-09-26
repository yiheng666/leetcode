class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> now,need;
        for (int i : nums)
            now[i]++;
        for (int i=0;i<nums.size();i++){
            int value = nums[i];
            if (now[value] == 0) continue;
            if (need[value] > 0){
                need[value]--;
                now[value]--;
                need[value+1]++;
            }
            else if (now[value] > 0 && now[value+1] > 0 && now[value+2] > 0){
                now[value]--;
                now[value+1]--;
                now[value+2]--;
                need[value+3]++;
            }
            else return false;
        }
        return true;
    }
};