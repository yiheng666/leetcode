class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int max = releaseTimes[0],n = keysPressed.size();
        for (int i=1;i<n;i++){
            int temp = releaseTimes[i] - releaseTimes[i-1];
            if (temp == max && res < keysPressed[i]){
                res = keysPressed[i];
            }
            if (temp > max){
                max = temp;
                res = keysPressed[i];
            }
        }
        return res;
    }
};