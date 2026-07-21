class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev_z=0,z=s[0]=='0'?1:0,cnt=s[0]-'0',ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                z++;
                if(prev_z>0) ans=max(ans,prev_z+z);
            }
            else{
                cnt++;
                if(s[i-1]=='0') prev_z=z;
                z=0;
            }
        }
        return cnt+ans;
    }
};
