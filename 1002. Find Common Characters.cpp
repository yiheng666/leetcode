class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        vector<int> dict(26);
        for (char c : words[0]) dict[c-'a']++;
        for (int i=1;i<words.size();i++){
            vector<int> temp(26);
            for (int j=0;j<words[i].size();j++){
                temp[words[i][j]-'a']++;
            }
            for (int i=0;i<26;i++){
                dict[i] = min(dict[i],temp[i]);
            }
        }

        for (int i=0;i<26;i++){
            if (dict[i] > 0){
                for (int j=0;j<dict[i];j++){
                    string s(1,'a'+i);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};