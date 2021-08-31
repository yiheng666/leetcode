class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>& board,int row,int col){
        if (col == 9){
            return dfs(board,row+1,0);
        }
        if (row == 9){
            return true;
        }
        if (board[row][col] != '.'){
            return dfs(board,row,col+1);
        }
        for (char a='1';a<='9';a++){
            if (!isValid(board,a,row,col)){
                continue;
            }
            board[row][col] = a;
            if (dfs(board,row,col+1)){
                return true;
            }
            board[row][col] = '.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board,char a,int row,int col){
        for (int i=0;i<9;i++){
            if (board[row][i] == a) return false;
            if (board[i][col] == a) return false;
            if (board[(row)/3*3 + i/3][(col)/3*3 + i%3] == a) return false;
        }
        return true;
    }
};