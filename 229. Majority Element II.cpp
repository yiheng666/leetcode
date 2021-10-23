class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = n / 3;
        unordered_map<int,int> m;
        unordered_map<int,int> flag;
        vector<int> res;
        for (int i=0;i<n;i++){
            if (flag[nums[i]]) continue;
            m[nums[i]]++;
            if (m[nums[i]] > x){
                res.push_back(nums[i]);
                flag[nums[i]] = 1;
            } 
        }
        return res;
    }
};