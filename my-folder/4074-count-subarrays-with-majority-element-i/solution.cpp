class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target) cnt++;
                if(2*cnt>j-i+1) ans++;
            }
        }
        return ans;
    }
};
