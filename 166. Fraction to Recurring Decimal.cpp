class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0"; 
        long a = numerator,b = denominator;
        string res = "";
        if ((a > 0 && b<0 ) || (a < 0 &&b > 0)) res += '-';
        a = abs(a);
        b = abs(b);
        res += to_string(a / b);
        if (a % b == 0) return res;
        res += '.';
        unordered_map<long,int> m;
        a = (a % b) * 10 ;
        while (a > 0 && m[a] == 0 ){
            m[a] = res.size();
            res += to_string(a / b);
            a = (a % b) * 10 ;
        }
        if (a == 0) return res;
        res.insert(m[a],"(");
        res += ")";
        return res;
    }
};