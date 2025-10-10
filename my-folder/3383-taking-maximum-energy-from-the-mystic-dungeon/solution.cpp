class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int>mp(k,0); int ans=INT_MIN;
        for(int i=0;i<k;i++){
            int sum=0;
            for(int j=i;j<energy.size();j+=k) sum+=energy[j];
            mp[i]=sum; ans=max(ans,mp[i]);
        }
        for(int i=k;i<energy.size();i++){
            mp[i%k]-=energy[i-k];
            ans=max(ans,mp[i%k]);
        }
        return ans;
    }
};
