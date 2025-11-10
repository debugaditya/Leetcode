class Solution {
public:
    const int MOD=1000000007;
    int numSub(string s) {
        int cnt=0; long long ans=0;
        for(auto &it:s){
            if(it=='1'){
                cnt++;
                ans=(ans+cnt)%MOD;
            }
            else cnt=0;
        }
        return ans;
    }
};
