class Solution {
public:
    int findComplement(int num) {
        int n = num;
        long twos =1; 
        while (n){
            n /= 2;
            twos *= 2;
        }
        return twos - num - 1;
    }
};