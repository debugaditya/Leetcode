class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>mp(26,0); int ans=0;
        for(auto it:s) mp[it-'a']++;
        for(auto it:t) mp[it-'a']--;
        for(auto it:mp) ans+=abs(it);
        return ans;
    }
};
