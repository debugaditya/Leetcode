class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>mp(101,0); vector<int>ans;
        for(auto it:bulbs) mp[it]=1-mp[it];
        for(int i=1;i<=100;i++) if(mp[i]==1) ans.push_back(i);
        return ans;
    }
};
