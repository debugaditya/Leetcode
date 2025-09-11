class Solution {
public:
    int gcd(int a,int b){
        if(min(a,b)==0) return max(a,b);
        return gcd(min(a,b),max(a,b)%min(a,b));
    }
    bool isGoodArray(vector<int>& nums) {
        int g=nums[0];
        for(auto it:nums){
            if(gcd(it,g)==1) return true;
            g=gcd(it,g);
        }
        return false;
    }
};
