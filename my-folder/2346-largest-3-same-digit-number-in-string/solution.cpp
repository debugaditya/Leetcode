class Solution {
public:
    string largestGoodInteger(string num) {
    int ans=-1; for(int i=1;i<num.size()-1;i++) if(num[i-1]==num[i]&&num[i]==num[i+1]) ans=max(ans,num[i]-'0'); if(ans==-1) return ""; string s=""; for(int i=0;i<3;i++) s+=ans+'0';return s;
    }
};
