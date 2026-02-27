class Solution {
public:
    int combi(int a,int b){
        long long ans=1;
        for(int i=b+1;i<=a;i++){
            ans*=i;
            ans/=i-b;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return combi(m+n-2,n-1);
    }
};
