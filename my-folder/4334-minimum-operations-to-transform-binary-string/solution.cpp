class Solution {
public:
    int minOperations(string s1, string s2) {
        int ans=0;
        for(int i=0;i<s1.size()-1;i++){
            if(s1[i]<=s2[i]) continue;
            else{
                if(s1[i+1]=='1'&&s2[i+1]=='0') ans++;
                else if(s1[i+1]==s2[i+1]) ans+=2;
                else ans+=3;
                s1[i]=s2[i]; s1[i+1]=s2[i+1];
            }
        }
        for(int i=0;i<s1.size();i++) if(s1[i]<s2[i]) {ans++; s1[i]=s2[i];}
        if(s1.back()!=s2.back()){
            if(s1.size()==1) return -1;
            return ans+2;
        }
        return ans;
    }
};
