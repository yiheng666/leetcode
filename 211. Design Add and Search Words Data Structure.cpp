class WordDictionary {
public:
    unordered_map<int,set<string>> m;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word.size()].insert(word);
    }
    
    bool search(string word) {
        for (string s : m[word.size()]){
            for (int j=0;j<word.size();j++){
                if (s[j] != word[j] &&  word[j] != '.'){
                    break;
                }
                if (j == word.size()-1){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */