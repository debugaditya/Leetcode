class Solution {
public:
    void update(int i,int l,int r,int &idx,int val,vector<int>&seg){
        if(l==r) {seg[i]=max(seg[i],val); return;}
        int mid=(l+r)/2;
        if(mid<idx) update(2*i+2,mid+1,r,idx,val,seg);
        else update(2*i+1,l,mid,idx,val,seg);
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
    int get(int i,int l,int r,int left,int right,vector<int>&seg){
        if(l>=left&&r<=right) return seg[i];
        if(l>right||r<left) return 0;
        int mid=(l+r)/2;
        return max(get(2*i+1,l,mid,left,right,seg),get(2*i+2,mid+1,r,left,right,seg));
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),[](auto &a,auto &b){
            if(a[0]==b[0])
                return a[1]>b[1];

            return a[0]<b[0];
        });
        int h=0,ans=1; 
        for(auto it:e) h=max(h,it[1]+1);
        vector<int>seg(4*h,0); update(0,0,h-1,e[0][1],ans,seg);
        for(int i=1;i<e.size();i++){
            int res=get(0,0,h-1,0,e[i][1]-1,seg);
            ans=max(ans,res+1);
            update(0,0,h-1,e[i][1],res+1,seg);
        }
        return ans;
    }
};
