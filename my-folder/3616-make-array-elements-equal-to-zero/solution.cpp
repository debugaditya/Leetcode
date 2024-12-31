class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0;
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]==0) mp[i]=sum;
        }
        for(auto it:mp){
            if(2*it.second==sum) ans+=2;
            if(2*it.second==sum+1) ans++;
            if(2*it.second==sum-1) ans++;
        }
        return ans;
    }
};
