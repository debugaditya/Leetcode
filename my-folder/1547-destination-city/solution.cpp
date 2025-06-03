class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;
        for(auto it:paths){mp[it[0]]--; mp[it[1]]++;}
        for(auto it:mp) if(it.second==1) return it.first;
        return "";
    }
};
