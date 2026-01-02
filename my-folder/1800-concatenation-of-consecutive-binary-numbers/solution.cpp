class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0,power=1;
        for(int i=n;i>0;i--){
            int temp=i;
            while(temp>0){
                ans=(ans+(temp%2)*power)%1000000007;
                power=(2*power)%1000000007; temp/=2;
            }
        }
        return ans;
    }
};
