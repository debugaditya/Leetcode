class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       vector<int>dup=nums; int s=-1,r=-2;
       sort(dup.begin(),dup.end());
       for(int i=0;i<dup.size();i++) if(dup[i]!=nums[i]) {s=i; break;} 
       for(int i=dup.size()-1;i>=0;i--) if(dup[i]!=nums[i]) {r=i; break;} 
       return r-s+1;
    }
};
