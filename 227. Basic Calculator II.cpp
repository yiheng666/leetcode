class Solution {
public:
    int calculate(string s) {
        int ans = 0,n = s.size(),num = 0;
        stack<int> st;
        char sign = '+';
        for (int i=0;i<n;i++){
            //这个判断不好用，费解
            //if (s[i] == ' ') continue;
            char c = s[i];
            if (isdigit(c)){
                num = 10 * num + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == n-1){
                if (sign == '+'){
                    st.push(num);
                }
                else if (sign == '-'){
                    st.push(-num);
                }
                else if (sign == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (sign == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                
                sign = c;
                num = 0;
            }
        }
        while (!st.empty()){
            ans += st.top();
            
            st.pop();
        }
        return ans;
    }
};