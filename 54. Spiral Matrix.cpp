class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(),n = matrix[0].size();
        int top = 0,left = 0,right = n-1,bottom = m-1;
        while (res.size() < m * n){
            if (top <= bottom){
                for (int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if (left <= right){
                for (int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if (top <= bottom){
                for (int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right){
                for (int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};