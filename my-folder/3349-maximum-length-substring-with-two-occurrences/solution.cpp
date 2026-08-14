class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0,ans=0; vector<int>mp(26,0); mp[s[0]-'a']++;
        while(r<s.size()){
            if(mp[s[r]-'a']==3){
                mp[s[l]-'a']--;
                l++;
            }
            else{
                ans=max(ans,r-l+1);
                r++; if(r<s.size()) mp[s[r]-'a']++;
            }
        }
        return ans;
    }
};
