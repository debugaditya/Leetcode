class Solution {
public:
    bool f(vector<int>& nums, vector<vector<int>>& q,int mid){
        vector<int>v(nums.size()+1,0);
        int sum=0;
        for(int i=0;i<=mid;i++){
            v[q[i][0]]+=q[i][2];
            v[q[i][1]+1]-=q[i][2];
        }
        for(int i=0;i<nums.size();i++){
            sum+=v[i];
            v[i]=sum;
            if(nums[i]>v[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        if(accumulate(nums.begin(),nums.end(),0LL)==0) return 0;
        int l=0;
        int r=q.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(nums,q,mid)){
                ans=mid+1;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
