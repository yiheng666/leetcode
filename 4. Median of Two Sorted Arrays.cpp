class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        int i = 0,j = 0,res1 = 0,res2 = 0;
        int times = ( m + n ) / 2;
        while (times >= 0){
            if (i < m && j < n){
                if (nums1[i] < nums2[j]){
                    res2 = res1;
                    res1 = nums1[i++];
                }
                else{
                    res2 = res1;
                    res1 = nums2[j++];
                }
            }
            else if (i<m){
                res2 = res1;
                res1 = nums1[i++];
            }
            else if (j<n){
                res2 = res1;
                res1 = nums2[j++];
            }
            times--;
        }
        return (m + n ) % 2 == 1 ? res1 / 1.0 : (res1 + res2) / 2.0;
    }
};