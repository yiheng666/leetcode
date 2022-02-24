class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n,0);
        for (int j=0;j<n;j++) res[j] = j;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (res[j] < 0 || res[j] >= n) continue;
                int dir = grid[i][res[j]];
                if (dir == 1){
                    if (res[j] == n-1 || grid[i][res[j]+1] == -1){
                        res[j] = -1;
                    }
                    else res[j] += 1;
                }
                else{
                    if (res[j] == 0 || grid[i][res[j]-1] == 1){
                        res[j] = -1;
                    }
                    else res[j] -= 1;
                }
            }
        }
        return res;
    }
};