class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string word,res;
        istringstream ss(path);
        while (getline(ss,word,'/')){
            if (word != "" && word != "." && word != ".."){
                v.push_back(word);
            }
            else if (word == ".." && !v.empty()){
                v.pop_back();
            }
        }
        if (v.empty()) return "/";
        for (auto &s : v){
            res += "/" + s;
        }
        return res;
    }
};