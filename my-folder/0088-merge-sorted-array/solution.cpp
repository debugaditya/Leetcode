class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size()>0&&nums1.back()==0) nums1.pop_back();
        while(nums2.size()>0&&nums2.back()==0) nums2.pop_back();
        for(auto it:nums2) nums1.push_back(it);
        while(nums1.size()<m+n) nums1.push_back(0);
        sort(nums1.begin(),nums1.end());
    }
};
