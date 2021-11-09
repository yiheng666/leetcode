class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> MapSecret,MapGuess;
        int a = 0,b = 0;
        for (int i=0;i<secret.size();i++){
            if (secret[i] == guess[i]){
                a++;
            }
            else{
                MapSecret[secret[i]]++;
                MapGuess[guess[i]]++;
            }
        }
        for (int i=0;i<=9;i++){
            b += min(MapSecret[i+'0'],MapGuess[i+'0']);
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};