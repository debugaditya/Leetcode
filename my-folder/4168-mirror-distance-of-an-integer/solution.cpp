class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n,a=0;
        while(temp>0){
            a*=10; a+=temp%10;
            temp/=10;
        }
        return abs(n-a);
    }
};
