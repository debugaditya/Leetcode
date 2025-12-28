class Solution {
public:
    long long minimumCost(int c1, int c2, int c3, int n1, int n2) {
        if(c3==min({c1,c2,c3})) return 1LL*max(n1,n2)*c3;
        if(c3<c1+c2){
            if(n1>n2&&c1>c3) return 1LL*max(n1,n2)*c3;
            if(n1<n2&&c2>c3) return 1LL*max(n1,n2)*c3;
            long long ans=1LL*min(n1,n2)*c3+1LL*(n1>=n2?1LL*(n1-n2)*c1:1LL*(n2-n1)*c2);
            return ans;
        }
        return 1LL*c1*n1+1LL*c2*n2;
    }
};
