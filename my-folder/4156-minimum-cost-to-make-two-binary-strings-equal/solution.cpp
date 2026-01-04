class Solution {
public:
    long long minimumCost(string s, string t, int f, int sw, int c) {
        long long zeroes=0,ones=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]&&s[i]=='0') zeroes++;
            if(s[i]!=t[i]&&s[i]=='1') ones++;
        }
        if(2*f<=sw) return 1LL*(zeroes+ones)*f;
        long long mini=min(zeroes,ones); ans+=sw*mini;
        zeroes-=mini; ones-=mini; long long rem=max(ones,zeroes);
        if(2*f<=sw+c) return ans+1LL*rem*f;
        ans+=(rem/2)*(sw+c);
        if(rem%2==1) ans+=f;
        return ans;
    }
};
