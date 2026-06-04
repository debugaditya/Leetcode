class Solution {
public:
    int MOD=1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int>p1={-1},p2={-1}; long long ans=0;
        vector<long long>mp1(nums1.size(),0),mp2(nums2.size(),0);
        mp1[0]=nums1[0]; mp2[0]=nums2[0];
        for(int i=0;i<nums1.size();i++){
            if(i>0) mp1[i]=nums1[i]+mp1[i-1];
            int idx=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            if(idx<nums2.size()&&nums2[idx]==nums1[i]){
                p1.push_back(i);
                p2.push_back(idx);
            }
        }
        p1.push_back(nums1.size()-1); p2.push_back(nums2.size()-1);
        for(int i=1;i<nums2.size();i++) mp2[i]=nums2[i]+mp2[i-1];
        for(int i=1;i<p1.size();i++){
            long long maxi;
            if(i==1) maxi=max(mp1[p1[i]],mp2[p2[i]]);
            else maxi=max(mp1[p1[i]]-mp1[p1[i-1]],mp2[p2[i]]-mp2[p2[i-1]]);   
            ans=(ans+maxi)%MOD;
        }
        return ans;
    }
};
