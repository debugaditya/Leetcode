class Solution {
public:
    const int mod=1e9+7;
    int distinctSubseqII(string s) {
        vector<int>mp(26,0); long long tot=0;
        for(auto it:s){
            long add=(tot+1)%mod;
            tot=(tot+add-mp[it-'a']+mod)%mod;
            mp[it-'a']=add;
        }
        return tot;
    }
};
