
/*case全过 但是超时了
class WordDictionary {
public:
    vector<string> v;
    WordDictionary() {
        v.resize(0);
    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        for (int i=0;i<v.size();i++){
            if (v[i].size() == word.size()){
                for (int j=0;j<word.size();j++){
                    if (v[i][j] != word[j] &&  word[j] != '.'){
                        break;
                    }
                    if (j == word.size()-1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
*/
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */