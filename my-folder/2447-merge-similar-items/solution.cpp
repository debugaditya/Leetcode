class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int>mp(1001,0); vector<vector<int>>ans;
        for(auto it:items1) mp[it[0]]+=it[1];
        for(auto it:items2) mp[it[0]]+=it[1];
        for(int i=0;i<1001;i++) if(mp[i]>0) ans.push_back({i,mp[i]});
        return ans;
    }
};
