class Solution {
public:
    int res = 0x3f3f3f3f;
    set<pair<string,int>> visit;
	//消除三个以上连续字符
    void EraseBoard(string &board){
        for (int slow=0,fast=0;fast<=board.size();fast++){
            if (fast < board.size() && board[slow] == board[fast]) continue;
            if (fast - slow >= 3){
                board.erase(slow,fast - slow);
                fast = 0;
            }
            slow = fast;
        }
    }
    void Traceback(string &board,string &hand,int step){
        if (step >= res) return;
        if (visit.count({board,step})) return;
        visit.insert({board,step});
        if (board.size() == 0){
            res = min(res,step);
            return;
        }
        if (hand.size() == 0) return;
        int m = board.size(),n = hand.size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                char ch = hand[j];
                hand.erase(hand.begin()+j);
                string nb = board;
                nb.insert(nb.begin()+i,ch);
                EraseBoard(nb);
                Traceback(nb,hand,step+1);
                hand.insert(hand.begin()+j,ch);
            }
        }
    }
    int findMinStep(string board, string hand) {
        Traceback(board,hand,0);
        return res == 0x3f3f3f3f ? -1 : res;
    }
};