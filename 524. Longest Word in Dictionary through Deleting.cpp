class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        set<string> se;
        string res = "";
        for (int i=0;i<dictionary.size();i++)
            se.insert(dictionary[i]);
        for (auto temp : se){
            if ( res.size() >= temp.size() ) continue;
            int i = 0,j = 0;
            while (i<temp.size() && j<s.size()){
                if (temp[i] == s[j]) i++;
                j++;
            }
            if (i == temp.size() && temp.size() > res.size()) res = temp; 
        }
        return res;
    }
};