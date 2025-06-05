class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string b) {
        vector<char>mp(26); for(int i=0;i<26;i++) mp[i]=i+'a';
        for(int i=0;i<s1.size();i++){
            char mini=min(mp[s1[i]-'a'],mp[s2[i]-'a']);
            char maxi=max(mp[s1[i]-'a'],mp[s2[i]-'a']);
            if(maxi==mini) continue;
            for(auto &it:mp) if(it==maxi) it=mini;
        }
        string ans="";
        for(auto it:b) ans+=mp[it-'a'];
        return ans;
    }
};
