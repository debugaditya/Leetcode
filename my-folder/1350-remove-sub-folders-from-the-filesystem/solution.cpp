class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,bool>mp; vector<string>ans;
        for(auto it:folder) mp[it]=true;
        for(auto it:folder){
            string s=""; bool d=true;
            for(auto it1:it){
                if(it1=='/'&&mp[s]) {d=false; break;} 
                s+=it1; 
            }
            if(d) ans.push_back(it);
        }
        return ans;
    }
};
