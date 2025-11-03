class Solution {
public:
    void f(vector<vector<int>>&v,int idx,int n,long long &ans){
        int i=0;
        while(n>0){
            ans+=idx-v[n%10][i];
            v[n%10][i]++;
            i++; n/=10;
        }
    }
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>>v(10,vector<int>(log2(nums[0])+1,0)); long long ans=0;
        for(int i=0;i<nums.size();i++) f(v,i,nums[i],ans);
        return ans;
    }
};
