class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.size() == 0) return 1;
        int townJudge = -1;
        unordered_map<int,int> mp;
        for (int i=0;i<trust.size();i++){
            mp[trust[i][0]] = -1;
            if ( mp[trust[i][1]] != -1){
                mp[trust[i][1]]++;
            }
        }
        int count = 0;
        for (auto& m : mp){
            if (m.second == n - 1){
                count++;
                townJudge = m.first;
                if (count > 1) break;
            }
        }
        return count == 1 ? townJudge : -1;
    }
};