class Solution {
public:
    static bool cmp(vector<int>& a,vector<int> &b){
        if (a[0] != b[0]) return a[0] > b[0];
        else return a[1] < b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        int res = 0,n = properties.size(),maxDefense = -1;
        for (int i=0;i<n;i++){
            if (maxDefense > properties[i][1]) res++;
            maxDefense = max(maxDefense,properties[i][1]);
        }
        return res;
    }
};