class Solution {
public:
    bool detectCapitalUse(string word) {
        int UpperLastPos = -1,LowerLastPos = -1;
        int n = word.size();
        for (int i=0;i<n;i++){
            if (word[i] >= 'A' && word[i] <='Z') UpperLastPos = i;
            else LowerLastPos = i; 
        }
        if(UpperLastPos>=1 && LowerLastPos>=0){
            return false;
        }
        return true;
    }
};