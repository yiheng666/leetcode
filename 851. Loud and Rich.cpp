const int maxn = 500+5;
int dp[maxn];
class Solution {
public:
    vector<int> q;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> query;
        int n = richer.size();
        int m = quiet.size();
        memset(dp,-1,sizeof dp);
        for(int i = 0;i < m;i++) query[quiet[i]] = i;
        for(int i = 0;i < n;i++){
            mp[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int>ans(m,0);
        q = quiet;
        for(int i = 0;i < m;i++){
            dfs(mp,i);
            ans[i] = query[dp[i]];
        }
        return ans;
    }
    int dfs(unordered_map<int,vector<int>>& mp,int u){
        if(dp[u] != -1) return dp[u];
        int ans = q[u];
        for(const auto& v : mp[u]){
            ans = min(dfs(mp,v),ans);
        }
        dp[u] = ans;
        return ans;
    }
};