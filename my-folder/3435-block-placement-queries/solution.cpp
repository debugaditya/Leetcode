class Solution {
public:
    int n=49999;
    vector<int>seg=vector<int>(4*n,0);
    void update(int idx,int val,int i,int l,int r){
        if(l==r){
            if(l==idx) seg[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid) update(idx,val,2*i+1,l,mid);
        else update(idx,val,2*i+2,mid+1,r);
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
    int get(int left,int right,int i,int l,int r){
        if(l>=left&&r<=right) return seg[i];
        if(l>right||r<left) return 0;
        int mid=(l+r)/2;
        return max(get(left,right,2*i+1,l,mid),get(left,right,2*i+2,mid+1,r));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int>st; st.insert(0); update(n,n,0,0,n); st.insert(n);
        vector<bool>ans;
        for(auto &it:queries){
            if(it[0]==1){
                int x=it[1];
                auto u=st.upper_bound(x);
                int nxt=*u;
                int pre=*prev(u);
                update(x,x-pre,0,0,n-1);
                update(nxt,nxt-x,0,0,n-1);
                st.insert(x);
            }
            else{
                int x=it[1],sz=it[2];
                auto u=st.upper_bound(x);
                int pre=*prev(u);
                int maxi=get(0,pre,0,0,n-1);
                ans.push_back(max(maxi,x-pre)>=sz);
            }
        }
        return ans;
    }
};
