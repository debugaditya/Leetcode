class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp; int ans=0;
        for(auto it:nums) mp[it]++;
        for(auto [it,freq]:mp){
            if(freq==1) return -1;
            else if(freq==2) ans++;
            else if(freq%3!=1) ans+=ceil(1.0*freq/3);
            else ans+=2+(freq-4)/3;
        }
        return ans;
    }
};
