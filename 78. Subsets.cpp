class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        dfs(nums,0,track);
        return ans;
    }
    void dfs(vector<int>& nums,int start,vector<int>& track){
        ans.push_back(track);
        for (int i=start;i<nums.size();i++){
            track.push_back(nums[i]);
            dfs(nums,i+1,track);
            track.pop_back();
        }
    }
};