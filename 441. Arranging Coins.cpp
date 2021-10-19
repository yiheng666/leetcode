class Solution {
public:
    int arrangeCoins(int n) {
        //求根公式
        return (int)( ( -1 + sqrt((8 * (long)n + 1)) ) / 2);
    }
};