class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int maxi=0; vector<int>mp(26,0); int cnt=0;
            for(int j=i;j<s.size();j++){
                mp[s[j]-'a']++;
                if(mp[s[j]-'a']==1) cnt++;
                if(mp[s[j]-'a']>maxi) maxi=mp[s[j]-'a'];
                if(maxi*cnt==j-i+1) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
