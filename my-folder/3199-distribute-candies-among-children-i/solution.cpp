class Solution {
public:
    int f(int idx,int sum,int &n,int &limit){
        if(idx==4) return sum==n?1:0;
        if(sum>n) return 0; int ans=0;
        for(int i=0;i<=min(n-sum,limit);i++) ans+=f(idx+1,sum+i,n,limit);
        return ans;
    }
    int distributeCandies(int n, int limit) {
        return f(1,0,n,limit);
    }
};
