class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<long long,long long>mp; 
        long long ans=1,can_share=0; 
        mp[1]=1;
        for(int i=2;i<=n;i++){
            can_share=(can_share-mp[i-forget]+1000000007)%1000000007;
            ans=(ans-mp[i-forget]+1000000007)%1000000007;
            mp[i-forget]=0;
            can_share=(can_share+mp[i-delay])%1000000007;
            ans=(ans+can_share)%1000000007;
            mp[i]=can_share;
        }
        return ans%1000000007;
    }
};

