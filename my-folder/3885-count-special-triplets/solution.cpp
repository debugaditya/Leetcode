class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mp1; unordered_map<int,int>mp2; int ans=0;
        for(int i=0;i<nums.size();i++){
            mp2[i]=mp1[2*nums[i]];
            mp1[nums[i]]++;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0) ans=(ans+1LL*mp2[i]*(mp1[0]-mp2[i]-1))%1000000007;
            else ans=(ans+mp2[i]*(mp1[2*nums[i]]-mp2[i]))%1000000007;
        }
        return ans;
    }
};
