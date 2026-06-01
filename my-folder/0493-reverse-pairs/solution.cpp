class Solution {
public:
    void update(long long i,long long l,long long r,long long val,unordered_map<long long,long long>&seg){
        if(l==r){
            if(l==val) seg[i]++;
            return;
        }
        long long mid=l+(r-l)/2;
        if(val<=mid) update(2*i+1,l,mid,val,seg);
        else update(2*i+2,mid+1,r,val,seg);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    long long get(long long i,long long l,long long r,long long left,long long right,unordered_map<long long,long long>&seg){
        if(r<left||l>right) return 0;
        if(l==r) return seg[i];
        if(l>=left&&r<=right) return seg[i];
        long long mid=l+(r-l)/2;
        return get(2*i+1,l,mid,left,right,seg)+get(2*i+2,mid+1,r,left,right,seg);
    }
    int reversePairs(vector<int>& nums) {
        unordered_map<long long,long long>seg; long long ans=0;
        for(long long i=0;i<nums.size();i++){
            long long n=2LL*nums[i]+1;
            ans+=get(0,INT_MIN,INT_MAX,n,INT_MAX,seg);
            update(0,INT_MIN,INT_MAX,nums[i],seg);
        }
        return ans;
    }
};
