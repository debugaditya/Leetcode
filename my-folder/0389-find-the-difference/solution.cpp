class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>mp(26,0);
        for(auto it:s) mp[it-'a']++;
        for(auto it:t) mp[it-'a']--;
        for(int i=0;i<26;i++) if(mp[i]==-1) return i+'a';
        return 'a';
    }
};
