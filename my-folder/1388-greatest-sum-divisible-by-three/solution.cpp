class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0); vector<int>mod1,mod2;
        sort(nums.begin(),nums.end());
        for(auto &it:nums){
            if(it%3==1) mod1.push_back(it);
            else if(it%3==2) mod2.push_back(it);
        }
        if(sum%3==1){
            if(mod1.size()==0&&mod2.size()<2) return 0;
            if(mod1.size()==0&&mod2.size()>=2) return sum-mod2[0]-mod2[1];
            int a=mod1[0]; 
            if(mod2.size()>=2) a=min(a,mod2[0]+mod2[1]);
            return sum-a;
        }
        else if(sum%3==2){
            if(mod2.size()==0&&mod1.size()<2) return 0;
            if(mod2.size()==0&&mod1.size()>=2) return sum-mod1[0]-mod1[1];
            int a=mod2[0]; 
            if(mod1.size()>=2) a=min(a,mod1[0]+mod1[1]);
            return sum-a;
        }
        return sum;
    }
};
