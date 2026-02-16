class Solution {
public:
    int reverseBits(int n) {
        int ans=0,pw=pow(2,30); n/=2;
        while(n>0){
            if(n%2==1) ans+=pw;
            pw/=2; n/=2;
        }
        return ans;
    }
};
