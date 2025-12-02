class Solution {
public:
    int ans=0;
    void f(int i,int n,vector<bool>&vis){
        if(i==n+1){ans++; return;}
        for(int j=1;j<=n;j++){
            if(!vis[j]&&(i%j==0||j%i==0)){
                vis[j]=true;
                f(i+1,n,vis);
                vis[j]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool>vis(n+1,false);
        for(int j=1;j<=n;j++){
            vis[j]=true;
            f(2,n,vis);
            vis[j]=false;
        }
        return ans;
    }
};
