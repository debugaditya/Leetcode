class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>freq(*max_element(nums.begin(),nums.end())+1,0),dp(*max_element(nums.begin(),nums.end())+1,0),result(nums.size());
        for(auto &it:nums) freq[it]++;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) continue; int sum=0;
            for(int j=0;j<freq.size();j++) sum+=freq[j]*abs(j-i);
            dp[i]=sum;
        }
        for(int i=0;i<nums.size();i++) result[i]=dp[nums[i]];
        return result;
    }
};
