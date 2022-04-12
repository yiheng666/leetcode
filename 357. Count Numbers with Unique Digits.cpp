class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        int product = 9;
        for (int i = 1; i < 10 && i <= n; i++) {
            res = product + res;
            product *= (10-i);
        }
        return res;
    }
}