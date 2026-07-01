class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        unordered_map<int,int>freq; for(auto it:nums) freq[it]++;
        sort(nums.begin(),nums.end()); int ans=-1,mini=INT_MAX;
        for(int i=nums.size()-1;i>=2;i--){
            if(i+1<nums.size()&&nums[i]==nums[i+1]) continue;
            freq[nums[i]]--;
            for(int j=i-1;j>=1;j--){
                if(j+1<i&&nums[j]==nums[j+1]) continue;
                freq[nums[j]]--;
                int idx=lower_bound(nums.begin(),nums.begin()+j-1,target-nums[i]-nums[j])-nums.begin();
                if(idx<nums.size()&&mini>abs(target-nums[i]-nums[j]-nums[idx])){
                    mini=abs(target-nums[i]-nums[j]-nums[idx]);
                    ans=nums[i]+nums[j]+nums[idx];
                }
                if(idx-1>=0&&mini>abs(target-nums[i]-nums[j]-nums[idx-1])){
                    mini=abs(target-nums[i]-nums[j]-nums[idx-1]);
                    ans=nums[i]+nums[j]+nums[idx-1];
                }
                freq[nums[j]]++;
            }
        } 
        return ans;
    }
};
