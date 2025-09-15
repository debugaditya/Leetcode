class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        for(int i=nums.size()-2;i>=0;i--) if(nums[i]<nums[i+1]){idx=i; break;}
        reverse(nums.begin()+idx+1,nums.end());
        if(idx==-1) return;
        int l=idx+1,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[idx]) r=mid-1;
            else l=mid+1;
        }
        swap(nums[idx],nums[l]);
        return;
    }
};
