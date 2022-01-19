class Solution {
public:
    vector<long double> memo;
    bool dfs(string& num,int start){
        if (start == num.size()){
            if (memo.size() < 3) return false;
            return true;
        }
        for (int i=start;i<num.size();i++){
            string temp = num.substr(start,i-start+1);
            if (temp[0] == '0' && temp.size() != 1) break;
            int n = memo.size();
            if (n < 2 || stold(temp) - memo[n-1] == memo[n-2]){
                memo.push_back(stold(temp));
                if (dfs(num,i+1)) return true;
                memo.pop_back();
            }
            if (n >=2 && stold(temp) - memo[n-1] > memo[n-2]) break;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return dfs(num,0);
    }
};