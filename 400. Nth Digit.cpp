class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9) return n;
        long long x = 1,index = 9,length = 0;
        for (;length + index * x < n;x++){
            length += index * x;
            index *= 10;
        }
        long long num = pow(10,x-1) + (n - length - 1) / x;
        long long pos = (n - length - 1) % x;
        return to_string(num)[pos] - '0';

    }
};