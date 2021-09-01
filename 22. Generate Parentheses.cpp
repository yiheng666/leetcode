class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generate(0,0,"",n);
        return ans;
    }
    void generate(int left,int right,string str,int n){
        if (left > n || right > n || left < right){
            return;
        }
        if (left == n && right == n){
            ans.push_back(str);
        }
        generate(left+1,right,str+'(',n);
        generate(left,right+1,str+')',n);
    }
};