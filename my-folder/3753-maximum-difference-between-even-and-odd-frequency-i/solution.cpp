class Solution {
public:
    int maxDifference(string s) {
        vector<int>mp(26,0);
        int odd=INT_MIN;
        int even1=INT_MAX;
        for(int i=0;i<s.size();i++) mp[(s[i]-'a')]++;
        for(int i=0;i<mp.size();i++){
            if(mp[i]%2!=0&&mp[i]!=0) odd=max(odd,mp[i]);
            if(mp[i]%2==0&&mp[i]!=0) even1=min(even1,mp[i]);  
        }
        return odd-even1;
    }
};
