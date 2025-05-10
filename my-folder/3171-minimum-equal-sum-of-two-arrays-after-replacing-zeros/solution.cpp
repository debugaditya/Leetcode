class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1=0,sum1=0,z2=0,sum2=0;
        for(auto it:nums1){
            sum1+=it;
            if(it==0) z1++;
        }
        for(auto it:nums2){
            sum2+=it;
            if(it==0) z2++;
        }
        sum1+=z1;
        sum2+=z2;
        if(sum1<sum2&&z1==0||sum2<sum1&&z2==0) return -1;
        return 1LL*max(sum1,sum2);
    }
};
