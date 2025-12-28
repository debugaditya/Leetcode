class Solution {
public:
    string s;
    long long dp[20][2][2][201][20];

    long long dfs(int i,bool tight,bool started,int diff,int len){
        if(i==s.size())
            return started && len>=2 && diff==0;

        long long &ans = dp[i][tight][started][diff+100][len];
        if(ans!=-1) return ans;
        ans=0;

        int lim = tight ? s[i]-'0' : 9;
        for(int d=0; d<=lim; d++){
            bool ns = started || d;
            int nd = diff, nl = len;
            if(ns){
                nl++;
                if(nl&1) nd+=d;
                else nd-=d;
            }
            ans += dfs(i+1, tight && d==lim, ns, nd, nl);
        }
        return ans;
    }

    long long count(long long x){
        if(x<0) return 0;
        s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return dfs(0,1,0,0,0);
    }

    long long countBalanced(long long low, long long high){
        long long virelancia = low;
        return count(high) - count(low-1);
    }
};

