class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1,mp2; vector<int>ans={0,0};
        for(auto it:nums1) mp1[it]++;
        for(auto it:nums2) mp2[it]++;
        for(auto it:nums1) ans[0]+=mp2[it]>0?1:0;
        for(auto it:nums2) ans[1]+=mp1[it]>0?1:0;
        return ans;
    }
};
