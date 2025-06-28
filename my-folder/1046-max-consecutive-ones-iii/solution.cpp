class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>zeroes; int cnt0=0,cnt1=0,ans=0; vector<int>mp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {zeroes.push_back(i); cnt0++;}
            else cnt1++;
            mp[i]=cnt1;
        }
        if(cnt0<=k) return nums.size();
        for(int i=0;i<=zeroes.size()-k;i++){
            if(i==0) ans=max(ans,mp[zeroes[k]]+k);
            else if(i==zeroes.size()-k) ans=max(ans,cnt1-mp[zeroes[i-1]]+k);
            else ans=max(ans,mp[zeroes[i+k]]-mp[zeroes[i-1]]+k);
        }
        return ans;
    }
};
