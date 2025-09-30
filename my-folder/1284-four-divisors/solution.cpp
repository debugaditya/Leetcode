class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end()),ans=0;
        unordered_map<int,int>mp; for(auto it:nums) mp[it]++;
        vector<pair<int,int>>v(maxi+1,{0,0});
        for(int i=1;i<=maxi;i++){
            if(v[i].first==3) ans+=mp[i]*(v[i].second+i);
            for(int j=i;j<=maxi;j+=i) {v[j].first++; v[j].second+=i;}
        }
        return ans;
    }
};
