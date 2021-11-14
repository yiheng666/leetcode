class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v;
        unordered_set<int> s;
        while (n){
            v.push_back(n%10);
            n /= 10;
        }
        sort(v.begin(),v.end());
        Insert(v,s);
		//next_permutation()函数功能是输出所有比当前排列大的排列，顺序是从小到大。
		//prev_permutation()函数功能是输出所有比当前排列小的排列，顺序是从大到小。
		//最小的那个取不到，要先插入。
        while (next_permutation(v.begin(),v.end())){
            Insert(v,s);
        }
        for (auto it=s.begin();it!=s.end();it++){
            if (Check(*it)){
                return true;
            } 
        }
        return false;
    }
    bool Check(int num){
		//bitset<n> b(para)即创建b为n为二进制数，para可以是整数，也可以是string,char[],
		//最低位index为0
        bitset<32> b(num);
        if (b.count() == 1) return true;
        else return false;
    }
    void Insert(vector<int> v,unordered_set<int> &s){
        if (v[0] != 0){
            int temp = v[0];
            for (int i=1;i<v.size();i++){
                temp = temp * 10 + v[i];
            }
            s.insert(temp);
        }
    }
};