class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=51;
        for(int i=0;i<nums.size();i++){
            int bit=0;
            for(int j=i;j<nums.size();j++){
                bit|=nums[j];
                if(bit>=k) ans=min(ans,j-i+1);
            }
        }
        return ans==51?-1:ans;
    }
};
