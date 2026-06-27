class Solution {
public:
    long long dp[20][11][2][2];
    long long f(int i,int prev,int started,int tight,string &s,int &k){
        if(i==s.size()) return 1;
        long long &res = dp[i][prev][started][tight];
        if (!tight && res != -1) return res;
        long long ans=0;
        int lim=(tight?s[i]-'0':9);
        for(int j=0;j<=lim;j++){
            if(!started&&j==0) ans+=f(i+1,10,0,(tight&&j==lim),s,k);
            else{
                if(!started||abs(prev-j)<=k) ans+=f(i+1,j,1,(tight&&j==lim),s,k);
            }
        }
        if (!tight) res = ans;
        return ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string s1=to_string(l-1),s2=to_string(r);
        memset(dp, -1, sizeof(dp));
        long long a1=f(0,10,0,1,s2,k);
        memset(dp, -1, sizeof(dp));
        long long a2=f(0,10,0,1,s1,k);
        return a1-a2;
    }
};
