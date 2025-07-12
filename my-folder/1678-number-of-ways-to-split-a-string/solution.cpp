class Solution {
public:
    int numWays(string s) {
        int cnt=0,len=0; long long ans=1;
        for(auto it:s) if(it=='1') cnt++;
        if(cnt%3!=0) return 0;
        if(cnt==0) return ((s.size()-1)*(s.size()-2)/2)%1000000007;
        int req=cnt/3; cnt=0;
        for(auto it:s){
            if(it=='1'){
                if(cnt==req){
                    ans=1LL*(ans*(len+1))%1000000007;
                    len=0; cnt=0;
                }
                cnt++;
            }
            else{
                if(cnt==req) len++;
            }
        }      
        return ans;
    }
};
