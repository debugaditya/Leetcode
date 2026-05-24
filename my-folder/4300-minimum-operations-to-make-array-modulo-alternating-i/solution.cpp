class Solution {
public:
    int f(int mod1,int mod2,int k,vector<int>& nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) ans+=min(abs((nums[i]%k)-mod1),k-abs((nums[i]%k)-mod1));
            else ans+=min(abs((nums[i]%k)-mod2),k-abs((nums[i]%k)-mod2));
        }
        return ans;
    }
    int minOperations(vector<int>& nums, int k) {
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i==j) continue;
                ans=min(ans,f(i,j,k,nums));
            }
        }
        return ans;
    }
};
