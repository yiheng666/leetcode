class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        dfs(nums,track);
        return ans;
    }
    void dfs(vector<int>& nums,vector<int>& track){
        if (nums.size() == track.size()){
            ans.push_back(track);
            return;
        }
        int n = nums.size();
        for (int i=0;i<n;i++){
            if (find(track.begin(),track.end(),nums[i]) != track.end())
                continue;
            track.push_back(nums[i]);
            dfs(nums,track);
            track.pop_back();
        }
    }
};