class Solution {
public:
    const long long MOD=1e9+7;
    long long f(long long n){
        long long cnt=0;
        while(n>1){
            long long temp=n/2;
            while(temp>1){
                if(n%temp==0) break;
                temp--;
            }
            if(temp==1) cnt++;
            n--;
        }
        return cnt;
    }
    long long factorial(long long cnt){
        long long ans=1;
        while(cnt>1){
            ans=(ans*cnt)%MOD;
            cnt--;
        }
        return ans;
    }
    long long numPrimeArrangements(long long n) {
        long long z=n;
        return (factorial(z-f(n))*factorial(f(n)))%MOD;
    }
};
