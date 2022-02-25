class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1,a2,b1,b2;
        for (int i=0;i<num1.size();i++){
            if (num1[i] == '+'){
                a1 = stoi(num1.substr(0,i));
                a2 = stoi(num1.substr(i+1,num1.size()-i-1));
                break;
            }
        }
        for (int i=0;i<num2.size();i++){
            if (num2[i] == '+'){
                b1 = stoi(num2.substr(0,i));
                b2 = stoi(num2.substr(i+1,num2.size()-i-1));
                break;
            }
        }
        int res1 = a1 * b1 - a2 * b2,res2 = a1 * b2 + a2 * b1;
        string res = to_string(res1) + "+" + to_string(res2) + "i";
        return res;
    }
};