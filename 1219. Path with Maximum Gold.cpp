class Solution {
public:
    int res = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] != 0){
                    dfs(grid,i,j,0);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int sum){
        int m = grid.size(),n = grid[0].size();
        if (i<0 || j<0 || i>=m || j >=n || grid[i][j] == 0) return;
        int gold = grid[i][j];
        grid[i][j] = 0;
        sum += gold;
        res = max(res,sum);
        dfs(grid,i+1,j,sum);
        dfs(grid,i-1,j,sum);
        dfs(grid,i,j+1,sum);
        dfs(grid,i,j-1,sum);
        sum -= gold;
        grid[i][j] = gold;
    }
};