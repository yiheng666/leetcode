class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> m;
        int n = s.size();
        for (int i=0;i <= n-10;i++){
            m[s.substr(i,10)]++;
        }
        for (auto it=m.begin();it!=m.end();it++){
            if (it->second > 1) v.push_back(it->first);
        }
        return v;
    }
};