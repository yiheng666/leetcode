class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT_MAX,right = INT_MIN,top = INT_MIN,bottom = INT_MAX;
        int n = rectangles.size();
        set<string> s;
        int sumArea = 0;
        for (int i=0;i<n;i++){
            sumArea += (rectangles[i][3] - rectangles[i][1] ) * (rectangles[i][2] - rectangles[i][0]);
            left = min(left,rectangles[i][0]);
            bottom = min(bottom,rectangles[i][1]);
            right = max(right,rectangles[i][2]);
            top = max(top,rectangles[i][3]);
            string lb = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][1]);
            string lt = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][3]);
            string rb = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][1]);
            string rt = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][3]);
            if (s.count(lb)) s.erase(lb);
            else s.insert(lb);
            if (s.count(lt)) s.erase(lt);
            else s.insert(lt);
            if (s.count(rb)) s.erase(rb);
            else s.insert(rb);
            if (s.count(rt)) s.erase(rt);
            else s.insert(rt);
        }
        if (s.size() == 4 && s.count(to_string(left) + " " + to_string(top)) && s.count(to_string(left) + " " + to_string(bottom)) && s.count(to_string(right) + " " + to_string(top)) && s.count(to_string(left) + " " + to_string(bottom)))
            return sumArea == (right - left)*(top - bottom);
        return false;
    }
};