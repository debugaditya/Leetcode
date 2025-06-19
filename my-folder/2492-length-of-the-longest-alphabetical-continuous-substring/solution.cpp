class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=0; int size=1;
        for(int i=1;i<s.size();i++){
            if(s[i]-s[i-1]==1) size++;
            else {ans=max(ans,size); size=1;}
        }
        ans=max(ans,size);
        return ans;
    }
};
