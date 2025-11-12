class Solution {
public:
    int minOperations(vector<int>& nums) {
        int mini=INT_MAX,sum=0; bool d=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) {d=true; sum++;}
            int hcf=nums[i];
            for(int j=i;j<nums.size();j++){
                hcf=gcd(hcf,nums[j]);
                if(hcf==1) {mini=min(j-i,mini); break;}
            }
        }
        if(sum==nums.size()) return 0;
        if(d) return nums.size()-sum;
        return mini==INT_MAX?-1:mini+nums.size()-1;
    }
};
