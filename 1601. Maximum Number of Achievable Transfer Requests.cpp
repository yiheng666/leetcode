class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int res = 0;
        vector<int> cnt(21);
        dfs(res,cnt,0,requests,0);
        return res;
    }
    void dfs(int&res,vector<int>&cnt,int idx,vector<vector<int>>&requests,int cur){
        if(idx==requests.size()){
             for(auto&i:cnt){
                if(i) return;
            }
            res = max(res,cur);
            return;
        }
        dfs(res,cnt,idx+1,requests,cur);
        cnt[requests[idx][0]]--;
        cnt[requests[idx][1]]++;
        dfs(res,cnt,idx+1,requests,cur+1);
        cnt[requests[idx][0]]++;
        cnt[requests[idx][1]]--;
    }
};