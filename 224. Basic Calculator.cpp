class Solution {
public:
    int calculate(string s) {
        int n = s.size(),res = 0,sign = 1; 
        stack<int> st;
        for (int i=0;i<n;i++){
            char c = s[i];
            if (isdigit(c)){
                int cur = c - '0';
                while (i+1 < n && isdigit(s[i+1])){
                    cur = cur * 10 + (s[++i] - '0');
                }
                res += cur * sign;
            }
            else if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (c == '('){
                st.push(res);
                res = 0;
                st.push(sign);
                sign = 1;
            }
            else if (c == ')'){
                int sign_top = st.top();st.pop();
                int num_top = st.top();st.pop();
                res = res * sign_top + num_top;
            }
        }
        return res;
    }
};
//超时了，但是很喜欢这个写法
class Solution {
public:
    int calculate(string& s) {
		int ans = 0,n = s.size(),num = 0;
        stack<int> st;
        char sign = '+';
        while (s.size()){
            char c = s[0];
            s = s.substr(1);
            if (isdigit(c)) num = 10 * num + (c - '0');
            if (c == '(') num = calculate(s);
            if ((!isdigit(c) && c != ' ') || s.size() == 0){
                if (sign == '+') st.push(num);
                else if (sign == '-') st.push(-num);
                sign = c;
                num = 0;
            }
            if (c == ')') break;
        }
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};