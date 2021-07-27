class Solution {
public:
    int dict(vector<int> &v,int n){
        if (n ==1 || n ==2 ) return 1;
        if (v[n] != 0) return v[n];
        v[n] = dict(v,n-1) + dict(v,n-2);
        return v[n];
    }
    int fib(int n) {
        if ( n < 1 ) return 0;
        vector<int> v(n+1,0);
        return dict(v,n);
    }
};