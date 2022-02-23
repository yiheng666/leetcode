class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1,s2;
        for (int num : nums1) s1.insert(num);
        for (int num : nums2) s2.insert(num);
        for (int it : s1){
            if (s2.count(it)){
                res.push_back(it);
            }
        } 
        return res;
    }
};