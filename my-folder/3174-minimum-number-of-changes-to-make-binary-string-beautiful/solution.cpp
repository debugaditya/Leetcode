class Solution {
public:
    int minChanges(string s) {
        int cnt=1;
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                if(cnt%2==0){
                    cnt=1;
                }
                else{
                    s[i+1]=s[i];
                    ans++;
                    i++;
                    cnt=1;
                
                }
            }
        }
        return ans;
    }
};
