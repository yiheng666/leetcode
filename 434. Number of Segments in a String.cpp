class Solution {
public:
    int countSegments(string s) {
        string str;
        istringstream input(s);
        int n = 0;
        while (input >> str){
            n++;
        }
        return n;
    }
};