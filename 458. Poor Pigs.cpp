class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(n + 1));
    }
};