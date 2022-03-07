class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool flg = false;
        if (num < 0){
            flg = true;
            num = -num;
        }
        string res;
        while (num){
            res += to_string(num % 7);
            num /= 7;
        }
        if (flg) res += '-';
        reverse(res.begin(),res.end());
        return res;
    }
};