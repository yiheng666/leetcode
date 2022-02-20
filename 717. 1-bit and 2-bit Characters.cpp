class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int res = 0;
        for (int i=bits.size()-2;i>=0;i--){
            if (bits[i] == 1) res++;
            else break;
        }
        return res % 2 == 0;
    }
};