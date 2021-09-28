class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star,left;
        for (int i=0;i<s.size();i++){
            char c = s[i];
            if (c == '(') left.push(i);
            else if (c == '*') star.push(i);
            else if (c == ')'){
                if (left.empty() && star.empty()) return false;
                if (!left.empty()) left.pop();
                else star.pop();
            }
        }
        while (!left.empty() && !star.empty()){
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int minCount = 0,maxCount = 0;
        for (int i=0;i<n;i++){
            if (s[i] == '('){
                minCount++;
                maxCount++;
            }
            else if (s[i] == ')'){
                minCount = max(minCount-1,0);
                maxCount--;
                if (maxCount < 0) return false;
            }
            else{
                minCount = max(minCount-1,0);
                maxCount++;
            }
        }
        return minCount == 0;
    }
};