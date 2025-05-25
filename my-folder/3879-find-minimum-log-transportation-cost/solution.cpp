class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans=0;
        while(n>k){
            n-=k;
            ans+=1LL*n*k;
        }
        while(m>k){
            m-=k;
            ans+=1LL*m*k;
        }
        return ans;
    }
};
