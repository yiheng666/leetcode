class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res = "";
        int n = words.size();
        unordered_map<char,int> mp;
        for (int i=0;i<licensePlate.size();i++){
            char c = licensePlate[i];
            if (c == ' ' || (c>='0' && c <= '9')) continue;
            mp[tolower(c)]++;
        }
        for (int i=0;i<n;i++){
            if (check(mp,words[i])){
                if (res == "") res = words[i];
                else res = res.size() > words[i].size() ? words[i] : res;
            }
        }
        return res;
    }
    bool check(unordered_map<char,int> &mp,string word){
        unordered_map<char,int> mapWord;
        for (int i=0;i<word.size();i++){
            char c = word[i];
            if (c == ' ' || (c>='0' && c <= '9')) continue;
            mapWord[tolower(c)]++;
        }
        for (auto it : mp){
            if (it.second > mapWord[it.first]) return false;
        }
        return true;
    }

};