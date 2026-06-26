class Solution {
public:
    unordered_map<long long,long long>mp;
    void update(long long i,int l,int r,int sum){
        if(l==r) {mp[i]++; return;}
        long long mid = l + ((long long)r - l) / 2;
        if(mid<sum) update(2*i+2,mid+1,r,sum);
        else update(2*i+1,l,mid,sum);
        mp[i]=mp[2*i+1]+mp[2*i+2];
    }
    long long get(long long i,int l,int r,int left,int right){
        if(left>r||right<l) return 0;
        if(left<=l&&r<=right) return mp[i];
        if(l==r) return mp[i];
        long long mid = l + ((long long)r - l) / 2;
        return get(2*i+1,l,mid,left,right)+get(2*i+2,mid+1,r,left,right);
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int sum=0; long long ans=0;
        update(0,INT_MIN,INT_MAX,sum);
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==target) sum++;
            else sum--;
            ans+=get(0,INT_MIN,INT_MAX,INT_MIN,sum-1);
            update(0,INT_MIN,INT_MAX,sum);
        }
        return ans;
    }
};
