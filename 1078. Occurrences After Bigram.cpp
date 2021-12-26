class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res,v;
        string word;
        istringstream ss(text);
        while (ss >> word){
            v.push_back(word);
        }
        int n = v.size();
        for (int i=0;i<n;i++){
            if (v[i] == first && v[i+1] == second && i+2<n){
                res.push_back(v[i+2]);
            }
        }
        return res;
    }
};