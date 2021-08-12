class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int left = 1,right = 1000000001;
         while (left < right){
             int mid = left + (right - left)/2;
             if (fun(piles,mid) <= h ){
                 right = mid;
             }
             else if (fun(piles,mid) > h ){
                 left = mid + 1;
             }
         }
         return left;
    }
    int fun(vector<int>& piles,int k){
        int hours = 0;
        for (int i=0;i<piles.size();i++){
            hours += piles[i] / k;
            if (piles[i] % k != 0){
                hours++;
            }
        }
        return hours;
    }
};