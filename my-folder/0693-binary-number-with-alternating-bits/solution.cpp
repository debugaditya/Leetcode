class Solution {
public:
    bool hasAlternatingBits(int n) {
        int mod=n%2; n/=2;
        while(n>0){
            if(n%2==mod) return false;
            n/=2; mod=1-mod;
        }
        return true;
    }
};
