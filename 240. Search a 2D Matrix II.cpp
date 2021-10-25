class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int i = 0 ,j = n-1;
        while ( i < m  && j >=0 ){
            int now = matrix[i][j];
            if (now == target) return true;
            else if (now < target) i++;
            else if (now > target) j--;
        }
        return false;   
    }
};