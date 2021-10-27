class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = area,R = 1;
        for (int i=2;i*i<=area;i++){
            if (area % i == 0){
                L = area / i;
                R = i;
            }
        }
        return {L,R};
    }
};
