class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        string ans="||"; vector<int>mp(26,0);
        for(auto it:s) mp[it-'a']++;
        for(int i=s.size()-1;i>=0;i--){
            vector<int>v=mp; bool d=true;
            string temp="";
            for(int j=0;j<i;j++){
                if(v[t[j]-'a']==0) {d=false; break;}
                temp+=t[j]; v[t[j]-'a']--;
            }
            if(!d) continue;
            int j=t[i]-'a'; j++;
            while(j<26&&v[j]==0) j++;
            if(j==26) continue;
            temp+=j+'a'; v[j]--;
            for(int k=0;k<26;k++){
                while(v[k]>0){
                    temp+=k+'a';
                    v[k]--;
                }
            }
            ans=min(ans,temp);
        }
        if(ans=="||") return "";
        return ans;
    }
};
