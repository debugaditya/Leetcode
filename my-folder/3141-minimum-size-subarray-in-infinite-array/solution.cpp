class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long n=nums.size(),sum=0,l=0,r=0,ans=INT_MAX; for(int i=0;i<n;i++) {sum+=nums[i]; nums.push_back(nums[i]);}
        int q=target/sum; target%=sum; sum=nums[0]; if(target==0) return q*n;
        while(r<nums.size()){
            if(sum==target) ans=min(r-l+1+q*n,ans);
            if(sum<=target){
                r++;
                if(r<nums.size()) sum+=nums[r];
                if(sum==target) ans=min(r-l+1+q*n,ans);
            }
            else if(sum>target){
                sum-=nums[l];
                l++; 
                if(r<l){
                    if(l<nums.size()) sum+=nums[l];
                    r++;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
