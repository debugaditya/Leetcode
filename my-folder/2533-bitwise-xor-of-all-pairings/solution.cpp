class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()%2==0&&nums2.size()%2==0) return 0;
        int ans1=0,ans2=0;
        for(int i=0;i<nums1.size();i++) ans1^=nums1[i];         
        for(int j=0;j<nums2.size();j++) ans2^=nums2[j];
        if(nums1.size()%2==0) return ans1;
        else if(nums2.size()%2==0) return ans2;
        else return ans1^ans2;
    }
};
