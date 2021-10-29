class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size(),res = 0;
        for (int i=0;i<n;i++){
            res += price[i] * needs[i];
        }
        for (auto offer : special){
            bool valid = true;
            for (int i=0;i<n;i++){
                if (offer[i] > needs[i]){
                    valid = false;
                }
                needs[i] -= offer[i];
            }
            if (valid){
                res = min(res,shoppingOffers(price,special,needs) + offer.back());
            }
            for (int i=0;i<n;i++){
                needs[i] += offer[i];
            }
        }
        return res;
    }
};