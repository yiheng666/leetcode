class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0,right = 0,res = 0;
        unordered_map<char,int> mp;
        while (right < answerKey.size()){
            char c = answerKey[right++];
            mp[c]++;
            while (min(mp['T'],mp['F']) > k){
                char d = answerKey[left++];
                mp[d]--;
            } 
            res = max(res,right - left);
        }
        return res;
    }
};