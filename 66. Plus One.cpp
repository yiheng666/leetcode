class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int flag = 1;
        reverse(digits.begin(),digits.end());
        for (int i=0;i<n;i++){
            if (flag){
                digits[i] += 1;
                flag = 0;
            }
            if (digits[i] >= 10){
                digits[i] = 0;
                flag = 1;
            }
            else break;
        }
        if (flag) digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};