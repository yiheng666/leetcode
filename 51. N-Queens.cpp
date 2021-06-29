class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    bool col[20],gl[20],ugl[20];
    void dfs(int row,int n){
        //end condition
        if (row == n){
            ans.push_back(board);
            return;
        }
        for (int i=0;i<n;i++){
            if (!col[i] && !gl[row+i] && !ugl[n-row+i]){
                col[i] = gl[row+i] = ugl[n-row+i] = true;
                board[row][i] = 'Q';
                dfs(row+1,n);
                board[row][i] = '.';
                col[i] = gl[row+i] = ugl[n-row+i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n,string(n, '.'));
        dfs(0,n);
        return ans;
    }
};