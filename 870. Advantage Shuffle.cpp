class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        for (int i:nums1) s.insert(i);
        vector<int> ans(nums1.size(),0);
        for (int i=0;i<nums2.size();i++){
            auto it = s.upper_bound(nums2[i]);
            if (it == s.end()) it = s.begin();
            ans[i] = *it;
            s.erase(it);
        }
        return ans;
    }
};