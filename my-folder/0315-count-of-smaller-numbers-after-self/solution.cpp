class Solution {
public:
    void update(int i,int l,int r,int &val,vector<int>&seg){
        if(l==r) {if(l==val) seg[i]++; return;}
        int mid=(l+r)/2;
        if(mid<val) update(2*i+2,mid+1,r,val,seg);
        else update(2*i+1,l,mid,val,seg);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int get(int i,int l,int r,int left,int right,vector<int>&seg){
        if(r<left || l>right) return 0;
        if(l==r) return seg[i];
        if(left<=l && r<=right) return seg[i];
        int mid=(l+r)/2;
        return get(2*i+2,mid+1,r,left,right,seg)+get(2*i+1,l,mid,left,right,seg);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>seg(80004,0),ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            int n=nums[i]+10000;
            ans[i]=get(0,0,20000,0,n-1,seg);
            update(0,0,20000,n,seg);
        }
        return ans;
    }
};
