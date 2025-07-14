class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0) return nums1==nums2?0:-1;
        long long cnt=0,sum=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==nums2[i]) continue;
            if(abs(nums1[i]-nums2[i])%k!=0) return -1;
            sum+=(nums1[i]-nums2[i])/k;
            if(nums1[i]>nums2[i]) cnt+=(nums1[i]-nums2[i])/k;
        }
        return sum==0?cnt:-1;
    }
};
