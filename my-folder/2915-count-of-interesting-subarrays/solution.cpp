class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int,int>mp1;
        int cnt=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%modulo==k) cnt++;
            ans+=mp1[(cnt%modulo-k+modulo)%modulo];
            mp1[cnt%modulo]++;
            if(cnt%modulo==k) ans++;
        }
        return ans;
    }
};
