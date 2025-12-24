class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm=p*q/gcd(p,q);
        int m=lcm/p,n=lcm/q;
        if(m%2==0 && n%2==1) return 0;
        if(m%2==1 && n%2==1) return 1;
        return 2;
    }
};
