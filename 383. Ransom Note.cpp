class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ran,mag;
        for (int i=0;i<ransomNote.size();i++){
            ran[ransomNote[i]]++;
        }
        for (int i=0;i<magazine.size();i++){
            mag[magazine[i]]++;
        }
        for (auto it : ran){
            if (mag[it.first] - it.second < 0){
                return false;
            }
        }
        return true;
        
    }
};