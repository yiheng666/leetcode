class Solution {
public:
    unordered_map<string,vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression]; 
        vector<int> ans;
        for (int i=0;i<expression.size();i++){
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for (int a : left){
                    for (int b : right){
                        if (c == '+') ans.push_back(a+b);
                        if (c == '-') ans.push_back(a-b);
                        if (c == '*') ans.push_back(a*b);
                    }
                }
            }
        }
        if (ans.size() == 0) ans.push_back(stoi(expression));
        memo[expression] = ans;
        return ans;
    }
};