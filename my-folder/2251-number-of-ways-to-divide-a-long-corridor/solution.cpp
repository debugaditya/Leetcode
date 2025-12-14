class Solution {
public:
    int numberOfWays(string c) {
        vector<int>idx; long long ans=1;
        for(int i=0;i<c.size();i++) if(c[i]=='S') idx.push_back(i);
        if(idx.size()%2==1||idx.size()==0) return 0;
        for(int i=1;i<idx.size();i+=2) if(i+1<idx.size()) ans=(1LL*ans*(idx[i+1]-idx[i]))%1000000007;
        return ans;
    }
};
