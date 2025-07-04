class Solution {
public:
    long long f(long long k){
        int l=0,r=63-__builtin_clzll(k); long long sma=-1;
        while(l<=r){
            int mid=(l+r)/2;
            long long p=1LL<<mid;
            if(p<=k) {sma=p; l=mid+1;}
            else r=mid-1;
        }
        return sma;
    }
    char kthCharacter(long long k, vector<int>& o) {
        if(k==1) return 'a';
        int cnt=0,i=63-__builtin_clzll(k-1); k--;
        while(k>0){
            k-=f(k);
            if(o[i]==1) cnt++;
            if(k>0) i=63-__builtin_clzll(k);
        }
        return (cnt%26)+'a';   
    }
};
