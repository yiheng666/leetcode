class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int mask=0xF8F0E080,answer=0xF0E0C000,cnt=0;
        for(int i:data){
            if(!cnt){
                for(cnt=0;cnt<4;++cnt)if(((i<<(cnt<<3))&mask)==((0xff<<(cnt<<3))&answer)) break;
                if(cnt==4) return false;
            }else{
                if((i&0xC0)!=0x80) return false;
                else --cnt;
            }
        }
        return cnt==0;
    }
};