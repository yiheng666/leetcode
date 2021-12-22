class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0,m=firstList.size(),n=secondList.size();
        vector<vector<int>> ans;
        while (i<m && j<n){
            int a1 = firstList[i][0],a2 = firstList[i][1];
            int b1 = secondList[j][0],b2 = secondList[j][1];
            if (a1 <= b2 && a2 >= b1){
                ans.push_back({max(a1,b1),min(a2,b2)});
            }
            if (a2 > b2) j++;
            else i++;
        }
        return ans;
    }
};