class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int sum = img[i][j];
                int num = 1;
                if (i>0){sum += img[i-1][j]; num++;}
                if (j>0){sum += img[i][j-1]; num++;} 
                if (i>0 && j>0){sum += img[i-1][j-1]; num++;} 
                if (i<m-1){sum += img[i+1][j]; num++;} 
                if (j<n-1){sum += img[i][j+1]; num++;} 
                if (i<m-1 && j<n-1){sum += img[i+1][j+1]; num++;} 
                if (i>0 && j<n-1){sum += img[i-1][j+1]; num++;} 
                if (i<m-1 && j>0){sum += img[i+1][j-1]; num++;} 
                res[i][j] = sum / num;
            }
        }
        return res;
    }
};