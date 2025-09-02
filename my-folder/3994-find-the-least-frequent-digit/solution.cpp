class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int>v(10,0); int ans=10;
        while(n>0){v[n%10]++; n/=10;}
        for(auto it:v) if(it!=0) ans=min(ans,it);
        for(int i=0;i<10;i++) if(v[i]==ans) return i;
        return -1;
    }
};
