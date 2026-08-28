class Solution {
public:
    string lexPalindromicPermutation(string s, string t) {
        vector<int>mp(26,0); int n=s.size(); char odd='|';
        for(auto it:s) mp[it-'a']++;
        for(int i=0;i<26;i++){
            if(mp[i]%2&&odd!='|') return "";
            if(mp[i]%2) odd=i+'a';
        }
        string ans="||";
        for(int i=0;i<n/2;i++){
            string temp(n,'|');
            vector<int>v=mp; bool d=true;
            if(n%2) {temp[n/2]=odd; v[odd-'a']--;}
            for(int j=0;j<i;j++){
                if(v[t[j]-'a']==0) {d=false; break;}
                temp[j]=t[j];
                temp[n-1-j]=t[j];
                v[t[j]-'a']-=2;
            }
            if(!d) continue;
            int j=t[i]-'a'; j++;
            while(j<26&&v[j]==0) j++;
            if(j==26) continue;
            temp[i]=j+'a'; temp[n-1-i]=j+'a'; v[j]-=2; int idx=i+1;
            for(int k=0;k<26;k++){
                while(v[k]>0){
                    temp[idx]=k+'a';
                    temp[n-1-idx]=k+'a';
                    v[k]-=2; idx++;
                }
            }
            ans=min(ans,temp);
        }
        string temp(n,'|');
        if(n%2) {temp[n/2]=odd; mp[odd-'a']--;}
        for(int j=0;j<n/2;j++){
            if(mp[t[j]-'a']==0) return ans=="||"?"":ans;
            temp[j]=t[j];
            temp[n-1-j]=t[j];
            mp[t[j]-'a']-=2;
        }
        if(temp<=t) return ans=="||"?"":ans;
        ans=min(ans,temp);
        return ans=="||"?"":ans;
    }
};
