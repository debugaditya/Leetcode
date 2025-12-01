class Solution {
public:
    bool check(int mid,vector<int>&nums){
        long long prev,curr=nums.back();
        for(int i=nums.size()-1;i>=1;i--){
            prev=nums[i-1];
            if(curr>mid) prev+=curr-mid;
            curr=prev; 
        }
        return prev<=mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l=*min_element(nums.begin(),nums.end()),r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,nums)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
