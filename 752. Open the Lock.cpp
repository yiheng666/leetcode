class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (find(deadends.begin(),deadends.end(),"0000")!=deadends.end())
            return -1;
        int step = 0;
        queue<string> q;
        set<string> visited;
        q.push("0000");
        visited.insert("0000");
        for (int i=0;i<deadends.size();i++)
            visited.insert(deadends[i]);
        while (!q.empty()){
            //这里一定要用sz，不能直接用i<q.size(),不然过不了
            int sz = q.size();
            for (int i=0;i<sz;i++){
                string cur = q.front();
                q.pop();
                if (cur == target) return step;
                for (int j=0;j<4;j++){
                    string up = upPlus(cur,j);
                    if (!visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = downPlus(cur,j);
                    if (!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    string upPlus(string s,int i){
        if (s[i] == '9') s[i] == '0';
        else s[i] += 1;
        return s;
    }
    string downPlus(string s,int i){
        if (s[i] == '0') s[i] = '9';
        else s[i] -= 1;
        return s;
    }
};