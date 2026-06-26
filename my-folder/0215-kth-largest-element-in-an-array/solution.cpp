class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end()),mini=*min_element(nums.begin(),nums.end());
        vector<int>mp(maxi+1-mini,0);
        for(auto &it:nums) mp[it-mini]++;
        for(int i=mp.size()-1;i>=0;i--){k-=mp[i]; if(k<=0) return i+mini;}
        return -1;
    }
};
