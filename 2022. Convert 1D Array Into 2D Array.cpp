class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size(),index = 0;
        vector<vector<int>> res;
        if (len != m * n) return res;
        for (int i=0;i<m;i++){
            vector<int> v;
            for (int j=0;j<n;j++){
                v.push_back(original[index++]);
            }
            res.push_back(v);
        }
        return res;
    }
};