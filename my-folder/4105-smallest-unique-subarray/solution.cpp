class Solution {
public:    
    bool check(int k,vector<int>&nums){
        const long long base = 911382323;
        const long long mod = 1e9 + 7;
        vector<long long> power(nums.size()+1, 1), hash(nums.size()+ 1, 0);
        for(int i=0;i<power.size()-1;i++){
            power[i+1]=(power[i]*base)%mod;
            hash[i+1]=(hash[i]*base+nums[i]+100000)%mod;
        }
        unordered_map<long long,int>mp;
        for(int i=0;i+k<=nums.size();i++){
            long long cur=(hash[i+k]-(hash[i]*power[k])%mod+mod)%mod;
            mp[cur]++;
        }
        for(auto &it:mp) if(it.second==1) return true;
        return false;
        
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int l=1,r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid,nums)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
