class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0,cnt=1,ans=0;
        for(int i=1;i<s.size();i++){
            ans+=abs(s[i]-s[i-1])*min(prev,cnt);
            prev=prev+abs(s[i]-s[i-1])*(cnt-prev); 
            cnt=cnt+1-abs(s[i]-s[i-1])*cnt;
        }
        ans+=min(prev,cnt);
        return ans;
    }
};
