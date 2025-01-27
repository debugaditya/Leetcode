class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));
        for(int i=0;i<=str1.size();i++) dp[i][0]=0;
        for(int i=0;i<=str2.size();i++) dp[0][i]=0;
        for(int i1=1;i1<=str1.size();i1++){
            for(int i2=1;i2<=str2.size();i2++){
                if(str1[i1-1]==str2[i2-1]) dp[i1][i2] =1+dp[i1-1][i2-1];
                else dp[i1][i2] =max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        int a=str1.size();
        int b=str2.size();
        string ans="";
        while(a!=0&&b!=0){
            if(str1[a-1]==str2[b-1]){
                ans+=str1[a-1];
                a--;
                b--;
            }
            else{
                if(dp[a-1][b]>=dp[a][b-1]){
                    ans+=str1[a-1];
                    a--;
                }
                else{
                    ans+=str2[b-1];
                    b--;
                }
            }
        }
        while (a>0) {
            ans+=str1[a - 1];
            a--;
        }
        while (b > 0) {
            ans += str2[b - 1];
            b--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
