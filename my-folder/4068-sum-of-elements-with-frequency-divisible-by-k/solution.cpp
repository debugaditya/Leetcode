class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int>mp(101,0); int sum=0;
        for(auto it:nums) mp[it]++;
        for(int i=0;i<101;i++){
            if(mp[i]!=0&&mp[i]%k==0) sum+=i*mp[i];
        } 
        return sum;
    }
};
