class Solution {
public:
    long long f(long long a,long long b){
        long long ans=1;
        for(long long i=a;i<=b;i++){
            ans*=i;
            ans/=i-a+1;
        }
        return ans;
    }
    long long uniquePaths(long long m, long long n) {
        long long a=max(m,n);
        long long ans=f(a,m+n-2);
        return ans;
    }
};
