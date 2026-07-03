class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            ans+=1LL*nums[i]*(mul>0?mul:1);
            mul--;
            k--; if(k==0) return ans;
        }
        return ans;
    }
};
