class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt=0;
        for(int i=1;i<=gcd(a,b);i++) if(a%i==b%i&&a%i==0) cnt++;
        return cnt;
    }
};
