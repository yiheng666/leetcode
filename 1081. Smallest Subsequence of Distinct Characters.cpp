class Solution {
public:
	//和316一样
    string smallestSubsequence(string s) {
        unordered_map<char,int> count;
        stack<char> stk;
        bool inStack[256]={false};
        string ans;
        for (char c:s) count[c]++;
        for (char c:s){
            count[c]--;
            if (inStack[c]) continue;
            while(!stk.empty() && stk.top() > c){
                if (count[stk.top()] == 0) break;
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c] = true;
        }
        while (!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};