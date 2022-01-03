class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        map<int,int> mp;
        for (int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        for (int i=0;i<n/groupSize;i++){
            int val = mp.begin()->first;
            if (--mp[val] == 0) mp.erase(val);
            for (int j=1;j<groupSize;j++){
                val++;
                if (mp.count(val) == 0) return false;
                if (--mp[val] == 0) mp.erase(val);
            }
        }
        return true;
    }
};