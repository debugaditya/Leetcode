class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0; reverse(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            int idx=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            idx=nums2.size()-1-idx;
            ans=max(ans,idx-i);
        }
        return ans;
    }
};
