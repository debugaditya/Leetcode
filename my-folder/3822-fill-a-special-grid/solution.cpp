class Solution {
public:
    void f(int x1,int x2,int y1,int y2,int l,int r,vector<vector<int>>&ans){
        if(l==r){
            ans[x1][y1]=l;
            return;
        }
        int quad=(r-l+1)/4; int size=(x2-x1+1)/2;
        int tr=l+quad-1,br=l+2*quad-1,bl=l+3*quad-1,bt=r;
        f(x1,x1+size-1,y1,y1+size-1,bl+1,r,ans);
        f(x1+size,x2,y1,y1+size,br+1,bl,ans);
        f(x1+size,x2,y1+size,y2,tr+1,br,ans);
        f(x1,x1+size-1,y1+size,y2,l,tr,ans);
    }
    vector<vector<int>> specialGrid(int n) {
        int side=1<<n;
        vector<vector<int>>ans(side,vector<int>(side));
        f(0,side-1,0,side-1,0,side*side-1,ans);
        return ans;
    }
};
