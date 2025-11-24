class Solution {
public:
    int titleToNumber(string c) {
        long long p=1,ans=0;
        for(int i=c.size()-1;i>=0;i--){
            ans+=(c[i]-'A'+1)*p;
            p*=26;
        }
        return ans;
    }
};
