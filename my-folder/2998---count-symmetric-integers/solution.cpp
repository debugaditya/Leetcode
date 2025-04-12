class Solution {
public:
    bool check(int n){
        int sum1=0,sum2=0;
        int s=trunc(log10(n)) + 1;
        for(int i=1;i<=s/2;i++){
            sum1+=n%10;
            n/=10;
        }
        for(int i=1;i<=s/2;i++){
            sum2+=n%10;
            n/=10;
        }
        return sum1==sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            int size=trunc(log10(i)) + 1;
            if(size%2==0&&check(i)) cnt++;
        }
        return cnt;
    }
};
