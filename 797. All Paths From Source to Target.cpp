class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph,0,path);
        return ans;
    }
    void traverse(vector<vector<int>>& graph,int s,vector<int>& path){
        path.push_back(s);
        int n = graph.size();
        if (s == n-1){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for (int v : graph[s]){
            traverse(graph,v,path);
        }
        path.pop_back();
    }
};