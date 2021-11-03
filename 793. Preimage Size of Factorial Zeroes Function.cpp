class Solution {
public:
    int preimageSizeFZF(int k) {
        return Upper_Bound(k) - Lower_Bound(k) + 1;
    }
    long Lower_Bound(int k){
        long left = 0,right = LONG_MAX;
        while (left < right){
            long mid = left + (right - left) / 2;
            if (trailingZeroes(mid) < k){
                left = mid + 1;
            }
            else if (trailingZeroes(mid) > k){
                right = mid;
            }
            else right = mid;
        }
        return left;
    }
    long Upper_Bound(int k){
        long left = 0,right = LONG_MAX;
        while (left < right){
            long mid = left + (right - left) / 2;
            if (trailingZeroes(mid) < k){
                left = mid + 1;
            }
            else if (trailingZeroes(mid) > k){
                right = mid;
            }
            else left = mid + 1;
        }
        return right - 1;
    }
    long trailingZeroes(long k){
        long ans = 0;
        while (k){
            ans += k / 5;
            k = k / 5;
        }
        return ans;
    }

};