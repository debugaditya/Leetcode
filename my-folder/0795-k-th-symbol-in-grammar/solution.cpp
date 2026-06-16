class Solution {
public:
    long long power(int mid){
        if(mid==0) return 1;
        long long temp=power(mid/2);
        long long ans=temp*temp;
        if(mid%2) ans*=2;
        return ans;
    }
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int len=power(n-1);
        if(k>len/2) return 1-kthGrammar(n-1,k-len/2);
        return kthGrammar(n-1,k);
    }
};
