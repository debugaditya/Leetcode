class Solution {
public:
    bool check(vector<int>& nums, int t,int div){
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=ceil((double)nums[i]/div);
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int l=1; int r=*max_element(nums.begin(),nums.end())+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,t,mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
