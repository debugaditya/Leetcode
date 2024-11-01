class Solution {
public:
    string makeFancyString(string s) {
        char x=s[0];
        int cnt=1;
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(x==s[i]){
                cnt++;
                if(cnt>=3){
                    continue;
                }
                else{
                    ans+=s[i];
                }
            }
            else{
                x=s[i];
                ans+=s[i];
                cnt=1;
            }
        }
        return ans;
        
    }
};
