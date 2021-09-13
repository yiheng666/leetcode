class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(),n = num2.size();
        vector<int> ans(m+n,0);
        string res;
        for (int i=m-1;i>=0;i--){
            for (int j=n-1;j>=0;j--){
                int p1 = i+j,p2 = i+j+1;
                int value = (num1[i] - '0') * (num2[j] - '0') + ans[p2];
                ans[p1] += value / 10 ;
                ans[p2] = value % 10;
            }
        }
        int index = 0;
        while (ans[index] == 0 && index < ans.size()) index++;
        for (int i=index;i<m+n;i++)
            res += ans[i] + '0';
        return res;
    }
};
