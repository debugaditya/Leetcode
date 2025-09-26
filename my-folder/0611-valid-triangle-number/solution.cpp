class Solution {
public:
    int idx(vector<int>&nums,int n){
        int l=0,r=nums.size()-1,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<n){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
    int triangleNumber(vector<int>& nums) {
        int cnt=0; sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) for(int j=i+1;j<nums.size();j++) {cnt+=max(0,idx(nums,nums[i]+nums[j])-j);}
        return cnt;
    }
};
