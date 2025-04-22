class Solution {
public:
    int reverse(int x) {
        if(x>=INT_MAX||x<=INT_MIN) return 0;
        long ans=0;
        long temp=abs(x);
        while(temp>0){
            ans*=10;
            ans+=temp%10;
            if(ans>INT_MAX) return 0;
            temp/=10;
        }
        return x<0?-ans:ans;
    }
};
