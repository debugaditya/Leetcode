class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) prod=1;
            else{
                prod*=nums[i];
                maxi=max(prod,maxi);
            }
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0) prod=1;
            else{
                prod*=nums[i];
                maxi=max(prod,maxi);
            }
        }
        return maxi;
    }
};
