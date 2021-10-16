class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        dfs(n,1,k,track);
        return ans;
    }
    void dfs(int n,int index,int k,vector<int>& track){
        if (track.size() == k){
            ans.push_back(track);
        }
        for (int i=index;i<=n;i++){
            track.push_back(i);
            dfs(n,i+1,k,track);
            track.pop_back();
        }
    }
};