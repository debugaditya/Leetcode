class Solution {
public:
    int numSteps(string s) {
        int ans=0,cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                ans+=cnt+1;
                if(cnt>0) cnt=1;
                else cnt=0;
            }
            else cnt++;
        }
        if(cnt>1) ans+=cnt+1;
        return ans;
    }
};
