class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> wordToNum;
        vector<string> res;
        string word,s = s1 + " " + s2;
        stringstream ss(s);
        while (ss >> word) wordToNum[word]++;
        for (auto it : wordToNum){
            if (it.second == 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};