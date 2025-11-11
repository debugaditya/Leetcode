class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int>v(s.size(),0); int cnt0=0,ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') cnt0++;
            v[i]=cnt0;
        }
        ans=min({ans,cnt0,(int)s.size()-cnt0});
        for(int i=0;i<s.size();i++) ans=min(ans,i+1-v[i]+cnt0-v[i]);
        return ans;
    }
};
