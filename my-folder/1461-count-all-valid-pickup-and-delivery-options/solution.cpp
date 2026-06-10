class Solution {
public:
    const int MOD=1e9+7;
    int countOrders(int n) {
        int len=2*n; long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=len*(len-1)/2;
            len-=2;
            ans%=MOD;
        }
        return ans;
    }
};
