class Solution {
public:
    static bool cmp(int a,int b){
        return a > b;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,string> mp;
        vector<int> v = score;
        vector<string> res;
        int n = score.size();
        sort(v.begin(),v.end(),cmp);
        vector<string> str = {"Gold Medal","Silver Medal","Bronze Medal"};
        for (int i=0;i<n;i++){
            if (i<=2){
                mp[v[i]] = str[i];
            }
            else mp[v[i]] = to_string(i+1);
        }
        for (int i=0;i<n;i++){
            res.push_back(mp[score[i]]);
        }
        return res;
    }
	
	// lambda 表达式，从大到小排序向量。根据num直接得出order
	vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> order;
        for(int i=0;i<nums.size();i++)
            order.push_back(i);
        sort(order.begin(),order.end(),[&nums](const int& a,const int& b){return nums[a]>nums[b];});
        vector<string> res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            switch(i)
            {
                case 0:res[order[i]]="Gold Medal";break;
                case 1:res[order[i]]="Silver Medal";break;
                case 2:res[order[i]]="Bronze Medal";break;
                default:res[order[i]]=to_string(i+1);break;
            }
        }
        return res;
    }
};