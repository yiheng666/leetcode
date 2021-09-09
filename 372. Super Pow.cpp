class Solution {
public:
    const int mod = 1337;
    int superPow(int a, vector<int>& b) {
        if (b.size() == 0) return 1;
        int last = b.back();
        b.pop_back();
        int part1 = myPow(a,last);
        int part2 = myPow(superPow(a,b),10);
        return (part1 * part2) % 1337;
    }
    int myPow(int a,int k){
        a %= mod;
        int ans = 1;
        for (int i=0;i<k;i++){
            ans *= a;
            ans %= mod;
        }
        return ans;
    }
};