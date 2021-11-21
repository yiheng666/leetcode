class Solution {
public:
	//用位运算，最后一位是0直接右移，最后两位都是1，且该数不是3是，就选择+1，
	//否则就选择－1，直到该数变成1，为防止越界，把n变成长整型 c代码
    int integerReplacement(int n) {
        int res = 0;
        long temp = n;
        while (temp != 1){
            if ((temp&3) == 3 && temp !=3) temp++;
            else if ((temp & 1) == 1) temp--;
            else temp >>= 1;
            res += 1;
        }
        return res;
    }
};