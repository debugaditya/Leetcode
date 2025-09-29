class Solution {
public:
    string majorityFrequencyGroup(string s1) {
        string s=""; int maxi=0,maxi1=0; vector<int>mp(26,0);
        for(auto it:s1) {mp[it-'a']++; maxi=max(maxi,mp[it-'a']);}
        for(int i=maxi;i>0;i--){
            string temp="";
            for(int j=0;j<26;j++) if(mp[j]==i) temp+=j+'a';
            if(s.size()<temp.size()) s=temp;
        }
        return s;
    }
};
