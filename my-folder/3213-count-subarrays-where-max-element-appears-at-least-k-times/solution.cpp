class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=nums[0];
        int cnt=0;
        long long ans=0;
        vector<int>mp={69};
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                ans=0;
                cnt=0;
                mp={69};
            }
            if(nums[i]==maxi){
                cnt++;
                mp.push_back(i);
            }
            if(cnt>=k) ans+=1LL*(mp[cnt-k+1]+1);
        }
        return ans;
    }
};
