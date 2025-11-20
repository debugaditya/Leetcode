class Solution {
public:
    vector<int>bits=vector<int>(32,0);
    int add(int it){
        int i=0,ans=0;
        while(it>0){
            if(it%2==1) bits[i]++;
            i++; it/=2; 
        }
        for(int i=31;i>=0;i--) {ans*=2; ans+=bits[i]>0;}
        return ans;
    }
    int remove(int it){
        int i=0,ans=0;
        while(it>0){
            if(it%2==1) bits[i]--;
            i++; it/=2; 
        }
        for(int i=31;i>=0;i--) {ans*=2; ans+=bits[i]>0;}
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0,OR=add(nums[0]),mini=nums.size()+1;
        while(j<nums.size()){
            if(OR<k){j++; if(j<nums.size()) OR=add(nums[j]);}
            else {
                mini=min(mini,j-i+1); OR=remove(nums[i]); i++;
                if(i>j){
                    if(i==nums.size()) break;
                    OR=add(nums[i]); j=i;
                } 
            }
        }
        return mini==nums.size()+1?-1:mini;
    }
};
