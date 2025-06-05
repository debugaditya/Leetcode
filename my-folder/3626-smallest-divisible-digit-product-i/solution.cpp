class Solution {
public:
    int prod(int n){
        int prod=1;
        while(n>0){
            prod*=n%10;
            n/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(prod(n)%t==0) return n;
            n++;
        }
        return -1;
    }
};
