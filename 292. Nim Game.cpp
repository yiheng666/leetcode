class Solution {
public:
    bool canWinNim(int n) {
        //巴什博奕，n%(m+1)!=0时，先手必赢
        return n % 4 != 0;
    }
};