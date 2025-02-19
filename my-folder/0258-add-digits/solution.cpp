class Solution {
public:
    int sum(int n){
        int ans=0;
        while(n>0){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int addDigits(int num) {
        while(num>9){
            num=sum(num);
        }
        return num;
    }
};
