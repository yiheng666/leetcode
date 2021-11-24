class Solution {
public:
    bool buddyStrings(string s, string goal) {
        string temp_s = "",temp_goal = "";
        if (s.size() <= 1 || goal.size() <= 1) return false;
        int n = s.size();
        if (goal.size() != n) return false;
        if (s == goal){
            for (int i=0;i<n;i++){
                for (int j=i+1;j<n;j++){
                    if (s[i] == s[j]) return true;
                }
            }
        }
        for (int i=0;i<n;i++){
            if (s[i] == goal[i]) continue;
            else{
                temp_s += s[i];
                temp_goal += goal[i];
            }
        }
        if (temp_s.size() != 2 || temp_goal.size() != 2) return false;
        reverse(temp_s.begin(),temp_s.end());
        return temp_s == temp_goal;
    }
};