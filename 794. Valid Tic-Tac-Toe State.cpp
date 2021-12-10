class Solution {
public:
    bool validTicTacToe(vector<string>& board) {

        int oCount = 0,xCount = 0,diff = 0;
        unordered_map<char,int> mp;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (board[i][j] == 'X') xCount++;
                if (board[i][j] == 'O') oCount++;
            }
        }
        diff = xCount - oCount;
        //1、X必须比O多1个或者相同，否则false； 
        if (diff < 0 || diff > 1) return false;
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) mp[board[0][0]]++;
        if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) mp[board[0][0]]++;
        if (board[2][2] == board[0][2] && board[2][2] == board[1][2]) mp[board[2][2]]++;
        if (board[2][2] == board[2][0] && board[2][2] == board[2][1]) mp[board[2][2]]++;
        if (board[1][1] == board[0][1] && board[1][1] == board[2][1]) mp[board[1][1]]++;
        if (board[1][1] == board[1][0] && board[1][1] == board[1][2]) mp[board[1][1]]++;
        if (board[1][1] == board[0][0] && board[1][1] == board[2][2]) mp[board[1][1]]++;
        if (board[1][1] == board[0][2] && board[1][1] == board[2][0]) mp[board[1][1]]++;
        //2、X和O不能同时都是赢家，否则false； 
        if (mp['X'] > 0 && mp['O'] > 0) return false; 
        //3、X赢的时候必须比O多1个，否则false；
        if (mp['X'] > 0 && diff != 1 ) return false;
        //4、O赢得时候个数与X相同，否则false；
        if (mp['O'] > 0 && diff != 0 ) return false;
        return true;
    }
};