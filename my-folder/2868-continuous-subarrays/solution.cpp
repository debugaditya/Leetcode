class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0; int i=0,j=0; unordered_map<int,int>mp;
        priority_queue<int>maxi; priority_queue<int,vector<int>,greater<int>>mini;
        maxi.push(nums[0]); mini.push(nums[0]); mp[nums[0]]++;
        while(j<nums.size()){
            while(mp[maxi.top()]==0) maxi.pop();
            while(mp[mini.top()]==0) mini.pop();
            if(maxi.top()-mini.top()<=2){
                ans+=j-i+1;
                j++;
                if(j<nums.size()){mp[nums[j]]++; maxi.push(nums[j]); mini.push(nums[j]);}
            }
            else{
                mp[nums[i]]--;
                i++;
            }
        }
        return ans;
    }
};
