class Solution {
public:
    string robotWithString(string s) {
        vector<char>mp(s.size()); char mini='z';
        string t=""; string ans="";
        for(int  i=s.size()-1;i>=0;i--){
            mini=min(s[i],mini);
            mp[i]=mini;
        }
        for(int i=0;i<s.size();i++){
            while(t.size()>0&&t.back()<=mp[i]){
                ans+=t.back();
                t.pop_back();
            }
            if(s[i]==mp[i]) ans+=s[i];
            else t+=s[i];
        }
        reverse(t.begin(),t.end()); ans+=t;
        return ans;
    }
};
