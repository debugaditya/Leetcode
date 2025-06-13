class Solution {
public:
    bool f(vector<int>& nums, int p,int maxi){
        int cnt=0;
        for(int i=1;i<nums.size();i++) if(nums[i]-nums[i-1]<=maxi){cnt++; i++;}
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end()); 
        int l=0; int r=nums.back()-nums.front();
        while(l<=r){
            int mid=(l+r)/2;
            if(f(nums,p,mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
