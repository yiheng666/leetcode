class Solution {
public:
    unordered_map<char,vector<int>> map;
    vector<vector<int>> memo;
    int findRotateSteps(string ring, string key) {
        int m = ring.size(),n = key.size();
        memo.resize(m,vector<int>(n,0));
        for (int i=0;i<ring.size();i++){
            map[ring[i]].push_back(i);
        }
        return minSteps(ring,0,key,0);
    }
    int minSteps(string ring,int i,string key,int j){
        int m = ring.size(),n = key.size(),ans = INT_MAX;
        if (j == n){
            return 0;
        }
        if (memo[i][j] != 0 ) return memo[i][j];
        for (int k:map[key[j]]){
            int step = abs(k-i);
            step = min(step,m-step);
            int nextSteps = minSteps(ring,k,key,j+1);
            ans = min(ans,1 + step + nextSteps);
        }
        memo[i][j] = ans;
        return ans;
    }
};