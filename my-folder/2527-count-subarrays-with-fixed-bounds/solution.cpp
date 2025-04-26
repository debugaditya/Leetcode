class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int mini=-1;
        int maxi=-1;
        int invalid=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK) mini=i; 
            if(nums[i]==maxK) maxi=i;
            if(nums[i]>maxK||nums[i]<minK){
                invalid=i;
                maxi=-1;
                mini=-1;
            }
            else if(maxi!=-1&&mini!=-1) ans+=1LL*(min(mini,maxi)-invalid);
        }
        return ans;
    }
};
