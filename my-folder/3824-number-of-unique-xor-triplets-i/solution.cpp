class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1; if(n==2) return 2;
        int l=0,r=32;
        while(l<=r){
            int mid=(l+r)/2;
            if(pow(2,mid)>n) r=mid-1;
            else l=mid+1;
        }
        return pow(2,l);
    }
};
