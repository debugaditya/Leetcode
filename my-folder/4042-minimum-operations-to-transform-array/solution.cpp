class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0; int mini=INT_MAX; int last=nums2.back(); bool d=false;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]<=last&&last<=nums2[i]||nums1[i]>=last&&last>=nums2[i]) d=true;
            else mini=min({mini,abs(last-nums1[i]),abs(last-nums2[i])});
            ans+=abs(nums1[i]-nums2[i]);
        }
        return d?ans+1:ans+mini+1;
    }
};
