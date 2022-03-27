class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sz = rolls.size();
        int allSum = 0,sum = 0,remainSum = 0;
        for (int num : rolls) sum += num;
        allSum = mean * (sz + n);
        remainSum = allSum - sum;
        if (remainSum > n * 6 || remainSum < n) return {};
        vector<int> res(n,remainSum / n);
        remainSum = remainSum - remainSum / n * n;
        for (int i=0;i<remainSum;i++){
            res[i]++;
        }
        return res;
    }
};