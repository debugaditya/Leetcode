class Solution {
public:
    int sum(int n){
        int s=0,p=1;
        while(n>0){
            s+=n%10;
            p*=n%10;
            n/=10;
        }
        return p+s;
    }
    bool checkDivisibility(int n) {
        return n%sum(n)==0;
    }
};
