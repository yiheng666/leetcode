class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(),res = 0;
        for (int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for (int j=0;j<n;j++){
                if (i == j) continue;
                int x = points[i][0] - points[j][0],y = points[i][1] - points[j][1];
                int dist = x*x + y*y;
                mp[dist]++;
            }
            for (auto it:mp){
                int cnt = it.second;
                res += cnt * (cnt-1);
            }
        }
        return res;
    }
};