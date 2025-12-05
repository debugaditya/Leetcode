class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>mp1(nums.size()),mp2(nums.size()),ans; mp1[0]=1; mp2[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) mp1[i]=1+mp1[i-1];
            else mp1[i]=1;
        }
        for(int i=nums.size()-2;i>=1;i--){
            if(nums[i]<=nums[i+1]) mp2[i]=1+mp2[i+1];
            else mp2[i]=1;
            if(mp1[i-1]>=k&&mp2[i+1]>=k) ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
