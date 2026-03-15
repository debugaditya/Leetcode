class Solution {
public:
    double myPow(double x, int n) {
        if(n==1) return x; if(n==0||x==1) return 1;
        double ans=myPow(x,abs(n/2));
        ans*=ans; if(n%2) ans*=x;
        return n<0?1.0/ans:ans;
    }
};
