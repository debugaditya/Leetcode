class NumArray {
public:
    vector<int>v,seg;
    void build(int i,int l,int r){
        if(l==r) {seg[i]=v[l]; return;}
        int mid=(l+r)/2;
        build(2*i+1,l,mid);
        build(2*i+2,mid+1,r);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    void edit(int i,int idx,int val,int l,int r){
        if(l==r){
            if(l==idx) seg[i]=val; 
            return;
        }
        int mid=(l+r)/2;
        if(mid>=idx) edit(2*i+1,idx,val,l,mid);
        else edit(2*i+2,idx,val,mid+1,r);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int get(int i,int l,int r,int left,int right){
        if(left>r||right<l) return 0;
        if(left<=l&&r<=right) return seg[i];
        int mid=(l+r)/2;
        if(mid>right) return get(2*i+1,l,mid,left,right);
        if(mid<left) return get(2*i+2,mid+1,r,left,right);
        return get(2*i+1,l,mid,left,right)+get(2*i+2,mid+1,r,left,right);
    }
    NumArray(vector<int>& nums) {
        for(auto &it:nums) v.push_back(it);
        int n =v.size();
        seg.resize(4*n);
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        edit(0,index,val,0,v.size()-1);
        
    }
    
    int sumRange(int left, int right) {
        return get(0,0,v.size()-1,left,right);
    }
};


