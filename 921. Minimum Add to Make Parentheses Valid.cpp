class Solution {
public:
    int minAddToMakeValid(string s) {
        int insert_left = 0,need_right = 0;
        for (int i=0;i<s.size();i++){
            if (s[i] == '(') need_right++;
            else{
                need_right--;
                if (need_right == -1){
                    insert_left++;
                    need_right = 0;
                }
            }
        }
        return insert_left + need_right;
    }
};