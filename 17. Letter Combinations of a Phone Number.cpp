class Solution {
public:
    vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        backtarck(digits,"",0);
        return res;
    }
    void backtarck(string digits,string s,int start){
        if (digits.size() == s.size()){
            res.push_back(s);
            return;
        }
        for (int i=start;i<digits.size();i++){
            int num = digits[i] - '0';
            for (char c : dict[num]){
                s.push_back(c);
                backtarck(digits,s,i+1);
                s.pop_back();
            }
        }
    }
};