class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto it:strs){
            string str="00000000000000000000000000";
            for(auto it1:it) str[it1-'a']++;
            mp[str].push_back(it);
        }
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};
