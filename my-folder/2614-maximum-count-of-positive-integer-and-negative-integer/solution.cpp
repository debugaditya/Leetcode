class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=0) r=mid-1;
            if(nums[mid]<0) l=mid+1;
        }
        int i1=r;
        l=0;
        r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>0) r=mid-1;
            if(nums[mid]<=0) l=mid+1;
        }
        int i2=l;
        return max(i1+1,(int) nums.size()-i2);
    }
};
