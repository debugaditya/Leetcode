class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<=60;i++){
            long long n=1LL*(num1-1LL*i*num2);
            if(n<0) return -1;
            if(__builtin_popcountll(n)<=i&&i<=n) return i;
        }
        return -1;
    }
};
