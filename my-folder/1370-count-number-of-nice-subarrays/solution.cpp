class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>odds; int ans=0;
        for(int i=0;i<nums.size();i++) if(nums[i]%2==1) odds.push_back(i);
        for(int i=k-1;i<odds.size();i++){
            if(i-k<0&&i+1==odds.size()) ans+=(odds[0]+1)*(nums.size()-odds[i]);
            else if(i-k<0) ans+=(odds[i+1]-odds[i])*(odds[0]+1);
            else if(i+1==odds.size()) ans+=(odds[i-k+1]-odds[i-k])*(nums.size()-odds[i]);
            else ans+=(odds[i+1]-odds[i])*(odds[i-k+1]-odds[i-k]);
        }
        return ans;
    }
};
