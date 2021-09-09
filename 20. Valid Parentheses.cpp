class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.size();i++){
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else{
                if (!st.empty() && st.top() == match(c)) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
    char match(char c){
        if (c == ')') return '(';
        if (c == '}') return '{';
        return '[';
    }
};