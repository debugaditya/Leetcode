class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mp(1001,0); vector<int>ans;
        for(auto it:nums1) mp[it]++;
        for(auto it:nums2){
            if(mp[it]>0) ans.push_back(it);
            mp[it]--;
        }
        return ans;
    }
};
