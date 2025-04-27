class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool>st(nums.size()+1,false);
        int ans=1;
        for(auto it:nums) if(it>0&&it<=nums.size()) st[it]=true;
        while(ans<=nums.size()){
            if(!st[ans]) return ans;
            ans++;
        }
        return ans;
    }
};
