class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i=0;i<n-1;i++){
            int count = 1;
            string s = "";
            for (int j=0;j<res.size()-1;j++){
                if (res[j] != res[j+1]){
                    s += to_string(count) + res[j];
                    count = 1;
                }
                else count++;
            }
            s += to_string(count) + res[res.size()-1];
            res = s;
        }
        return res;
    }
};