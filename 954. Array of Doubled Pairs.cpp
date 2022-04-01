class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<double, double> m;
        for (auto& num : A) {
            m[num]++;
        }
        for (auto& [c, d] : m) {
            if (d < 0) return false;
            if (d == 0) continue;
            if (c > 0) {
                if (!m.count(c * 2)) return false;
                m[c * 2] -= d;
            } else {
                if (!m.count(c / 2.0)) return false;
                m[c / 2.0] -= d;
            }
        }
        return true;
    }
};