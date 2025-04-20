class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>>ans;
        map<int,vector<int>>mp;
        for(int i=0;i<g.size();i++){
            int it=g[i];
            mp[it].push_back(i);
            if(mp[it].size()==it){
                ans.push_back(mp[it]);
                mp[it]={};
            }
        }
        return ans;
    }
};
