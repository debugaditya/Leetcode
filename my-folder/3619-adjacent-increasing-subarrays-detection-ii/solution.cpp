class Solution {
public:
    bool check(int mid,vector<int>&mp){
        for(int i=2*mid-1;i<mp.size();i++) if(mp[i]>=2*mid||(mp[i-mid]>=mid&&mp[i]>=mid)) return true;
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>mp(nums.size(),0);
        int cnt=1; mp[0]=1;
        for(int i=1;i<mp.size();i++){
            if(nums[i]>nums[i-1]) cnt++;
            else cnt=1;
            mp[i]=cnt;
        }
        int l=1,r=nums.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,mp)) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};
