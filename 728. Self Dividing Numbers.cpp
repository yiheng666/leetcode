class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i=left;i<=right;i++){
            if (isSelfdividingNumber(i)) res.push_back(i);
        }
        return res;
    }
    bool isSelfdividingNumber(int n){
        int remain = n;
        while (remain){
            int temp = remain % 10;
            remain /= 10;
            if (temp == 0 || n % temp != 0) return false;
        }
        return true;
    }
};