class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,false)),col(9,vector<bool>(9,false)),block(9,vector<bool>(9,false));
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int blockIndex = i / 3 * 3 + j / 3;
                    if (row[i][num] || col[j][num] || block[blockIndex][num]) return false;
                    else {
                        row[i][num] = true;
                        col[j][num] = true;
                        block[blockIndex][num] = true;
                    }
                }
            }
        }
        return true;
    }
};