class Solution {
public:
    int mod=1e9+7;
    long long power(int p){
        if(p==0) return 1;
        long long a=power(p/2);
        a%=mod; a*=a; a%=mod;
        if(p%2) a*=10;
        return a%mod;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        unordered_map<int,long long>mp,num,cnt; long long n=0,c=0; mp[-1]=0; num[-1]=0;
        vector<int>v;
        for(int i=0;i<s.size();i++){
            mp[i]=mp[i-1]+(s[i]-'0');
            if(s[i]!='0'){n*=10; n+=s[i]-'0'; n%=mod; c++;}
            num[i]=n; cnt[i]=c;
        }
        for(auto it:queries){
            long long sum=mp[it[1]]-mp[it[0]-1];
            long long nm=(1ll*num[it[1]]-1LL*num[it[0]-1]*power(cnt[it[1]]-cnt[it[0]-1]))%mod;
            nm+=mod; nm%=mod;
            long long ans=nm*sum; ans%=mod;
            v.push_back(ans);   
        }
        return v;
    }
};
