class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        unordered_map<int,int> m;
        for (int i : arr){
            m[i] = m[i-difference] + 1;
            res = max(m[i],res);
        }
        return res;
    }
};