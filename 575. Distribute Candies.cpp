class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int n = candyType.size();
        int res = 1,now = candyType[0];
        for (int i=1;i<n;i++){
            if (res == n / 2) break;
            if (candyType[i] != now){
                now = candyType[i];
                res++;
            } 
        }
        return res;
    }
};