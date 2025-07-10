class Solution {
public:
    int maxFreeTime(int e, vector<int>& s, vector<int>& end) {
        vector<int>br; br.push_back(s[0]-0); int ans=0,maxi=0;
        for(int i=1;i<s.size();i++) br.push_back(s[i]-end[i-1]);
        br.push_back(e-end.back()); unordered_map<int,int>mp1; unordered_map<int,int>mp2;
        for(int i=br.size()-1;i>=0;i--){maxi=max(maxi,br[i]); mp1[i]=maxi;} maxi=0;
        for(int i=0;i<br.size();i++){maxi=max(maxi,br[i]); mp2[i]=maxi;}
        for(int i=0;i<s.size();i++){
            if(i!=s.size()-1&&mp1[i+2]>=end[i]-s[i]) ans=max(ans,br[i]+br[i+1]+end[i]-s[i]);
            if(i!=0&&mp2[i-1]>=end[i]-s[i]) ans=max(ans,br[i]+br[i+1]+end[i]-s[i]);
            ans=max(ans,br[i]+br[i+1]);
        }
        return ans;
    }
};
