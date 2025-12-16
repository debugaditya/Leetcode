class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int maxi=1,i=0,j=0,ans=0; vector<int>mp(26,0); mp[s[0]-'a']++;
        while(j<s.size()){
            if(maxi==k){
                ans+=s.size()-j; mp[s[i]-'a']--;
                if(s[i]==s[j]) maxi=k-1;
                else maxi=k;
                i++;
            }
            else{
                j++;
                if(j<s.size()) mp[s[j]-'a']++;
                if(j<s.size()) maxi=max(maxi,mp[s[j]-'a']);
            }
        }
        return ans;
    }
};
