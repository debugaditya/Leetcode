class Solution {
public:
    long long check(vector<int>& nums,int mid){
        long long sum=0;
        for(auto it:nums) sum+=1LL*abs(it-mid);
        return sum;
    }
    int minMoves2(vector<int>& nums) {
        int ans=INT_MAX;
        int l=*min_element(nums.begin(),nums.end()),r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            long long mid=(l+r)/2,check1=check(nums,mid),check2=check(nums,mid+1);
            ans=min({(long long)ans,(long long)check1,(long long)check2});
            if(check1>=check2) l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
