class Solution {
public:
    int countHomogenous(string s) {
        int i=0; int j=0; int ans=0;
        while(j<s.size()){
            if(s[j]==s[i]){j++; ans=(ans+j-i)%1000000007;}
            else i=j;
        }
        return ans;
    }
};
