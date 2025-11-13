class Solution {
public:
    int peak(vector<int>& nums){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid==nums.size()-1) return -1;
            if(nums[mid]>nums[mid+1]) return mid;
            if(nums[mid]<nums[0]) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,idx=peak(nums);
        cout<<idx;
        if(idx!=-1&&nums[idx]>=target&&target>=nums[0]) r=idx;
        else l=idx+1; 
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};
