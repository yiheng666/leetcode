class Solution {
public:
    string originalDigits(string s) {
        vector<string> dict = {"zero","six","eight","two","seven","five","four","three","one","nine"};
        string str_number = "0682754319";
        unordered_map<char,int> m;
        string res = "";
        for (int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for (int i=0;i<10;i++){
            int min_letter = INT_MAX;
            for (int j=0;j<dict[i].size();j++){
                min_letter = min(min_letter,m[dict[i][j]]);
            }
            if (min_letter != 0){
                res.insert(res.size(),min_letter,str_number[i]);
                for (int j=0;j<dict[i].size();j++){
                    m[dict[i][j]] -= min_letter;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};