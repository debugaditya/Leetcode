class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans=0; long long num=0; bool d=true;
        for(int i=s.size()-1;i>=0;i--){
            if(d&&s[i]=='1'){
                if(s.size()-1-i<60){
                    num+=pow(2,s.size()-1-i);
                    if(num<=k) ans++;
                    else d=false;
                }
                else d=false;
            }
            else if(s[i]=='0') ans++;
        }
        return ans;
    }
};
