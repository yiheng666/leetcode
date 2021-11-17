class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int res = 0;
        vector<int> hash(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<words[i].size();j++){
                hash[i] |= 1 << (words[i][j] - 'a');
            }
        }
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (!(hash[i] & hash[j])){
                    int temp = words[i].size() * words[j].size();
                    res = max(res,temp);
                }
            }
        }
        return res;
    }
};