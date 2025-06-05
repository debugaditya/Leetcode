class Solution {
public:
    long long validSubstringCount(string w1, string w2) {
        long long ans=0; long long cnt=0; int unique=0;
        vector<int>mp1(26,0); vector<int>mp2(26,0);
        for(auto it:w2) mp2[it-'a']++;
        for(auto it:mp2) if(it>0) unique++;
        int l=0; int r=0; mp1[w1[0]-'a']=1;
        if(mp2[w1[0]-'a']==1) cnt++;
        while(r<w1.size()){
            if(cnt==unique){
                ans+=w1.size()-r;
                mp1[w1[l]-'a']--;
                if(mp1[w1[l]-'a']<mp2[w1[l]-'a']) cnt--;
                l++;
            }
            else{
                r++;
                if(r==w1.size()) break;
                mp1[w1[r]-'a']++;
                if(mp1[w1[r]-'a']==mp2[w1[r]-'a']) cnt++;
            }
        }
        return ans;
    }
};
