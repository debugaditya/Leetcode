class Solution {
public:
    void build(int i,int l,int r,vector<int>& nums,vector<int>& seg1,vector<int>& seg2){
        if(l==r){
            seg1[i]=seg2[i]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*i+1,l,mid,nums,seg1,seg2);
        build(2*i+2,mid+1,r,nums,seg1,seg2);
        seg1[i]=max(seg1[2*i+1],seg1[2*i+2]);
        seg2[i]=min(seg2[2*i+1],seg2[2*i+2]);
    }
    int mini(int i,int l,int r,int ql,int qr,vector<int>& seg2){
        if(ql<=l&&r<=qr) return seg2[i];
        if(l>qr||r<ql) return INT_MAX;
        int mid=(l+r)/2;
        return min(mini(2*i+1,l,mid,ql,qr,seg2),mini(2*i+2,mid+1,r,ql,qr,seg2));
    }
    int maxi(int i,int l,int r,int ql,int qr,vector<int>& seg1){
        if(ql<=l&&r<=qr) return seg1[i];
        if(l>qr||r<ql) return INT_MIN;
        int mid=(l+r)/2;
        return max(maxi(2*i+1,l,mid,ql,qr,seg1),maxi(2*i+2,mid+1,r,ql,qr,seg1));
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0; int n=nums.size(); vector<int>seg1(4*n),seg2(4*n);
        build(0,0,n-1,nums,seg1,seg2);
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int l=0;l<n;l++) pq.push({maxi(0,0,n-1,l,n-1,seg1)-mini(0,0,n-1,l,n-1,seg2),{l,n-1}});
        while(k>0){
            auto [val,p]=pq.top();
            auto [l,r]=p;
            pq.pop(); ans+=val;
            k--; 
            if(l<r) pq.push({maxi(0,0,n-1,l,r-1,seg1)-mini(0,0,n-1,l,r-1,seg2),{l,r-1}});
        }
        return ans;
    }
};
