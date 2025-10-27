class Solution {
public:
    void add(int n,int &bit,vector<int>&mp){
        int i=0;
        while(n>0){
            if(n%2==1) {mp[i]++; if(mp[i]==1) bit+=pow(2,i);}
            n/=2; i++;
        }
    }
    void remove(int n,int &bit,vector<int>&mp){
        int i=0;
        while(n>0){
            if(n%2==1) {mp[i]--; if(mp[i]==0) bit-=pow(2,i);}
            n/=2; i++;
        }
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int>prefix(nums.size(),0),ans(nums.size()),mp(32,0); int bit=0,l=0,r=0; prefix[nums.size()-1]=nums.back();
        for(int i=nums.size()-2;i>=0;i--) prefix[i]=prefix[i+1]|nums[i]; bit=0; add(nums[0],bit,mp);
        while(l<nums.size()){
            if(bit==prefix[l]){
                remove(nums[l],bit,mp);
                ans[l]=r-l+1; 
                l++;
                if(l>r&&l<nums.size()){
                    add(nums[l],bit,mp);
                    r++;
                }
            }
            else{
                r++;
                if(r<nums.size()) add(nums[r],bit,mp); 
            }
        }
        return ans;
    }
};
