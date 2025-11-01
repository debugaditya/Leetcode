class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long cnt=0,sum=0,ans=0; unordered_map<int,int>mp;
        for(int i=0;i<k;i++){mp[nums[i]]++; if(mp[nums[i]]==1) cnt++; sum+=nums[i];}
        for(int i=k-1;i<nums.size();i++){
            if(cnt>=m) ans=max(ans,sum);
            mp[nums[i-k+1]]--; if(mp[nums[i-k+1]]==0) cnt--;
            sum-=nums[i-k+1];
            if(i+1<nums.size()){
                mp[nums[i+1]]++; if(mp[nums[i+1]]==1) cnt++;
                sum+=nums[i+1];
            }
        }
        return ans;
    }
};
