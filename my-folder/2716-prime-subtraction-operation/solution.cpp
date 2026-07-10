class Solution {
public:
    void sieve(vector<int>&v){
        for(int i=2;i<v.size();i++){
            if(v[i]==-1){
                for(int j=2*i;j<v.size();j+=i) v[j]=0;
                for(int j=i-1;j>=0;j--){
                    if(v[j]>0) break;
                    v[j]=i;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int>v(1010,-1); sieve(v);
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]) continue;
            int diff=nums[i]-nums[i+1];
            if(v[diff]>=nums[i]) return false;
            nums[i]-=v[diff];
        }
        return true;
    }
};
