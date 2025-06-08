class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int cnt1=count(nums.begin(),nums.end(),1);
        int cnt2=count(nums.begin(),nums.end(),-1);
        if(cnt1%2==1&&cnt2%2==1) return false; 
        int idx1=-1; int idx2=-1; int b=0; int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1&&idx1!=-1){
                b+=i-idx1;
                idx1=-1;
            }
            else if(nums[i]==1&&idx1==-1) idx1=i;
            if(nums[i]==-1&&idx2!=-1){
                c+=i-idx2;
                idx2=-1;
            }
            else if(nums[i]==-1&&idx2==-1) idx2=i;
        }
        if(idx1!=-1) b=INT_MAX;
        if(idx2!=-1) c=INT_MAX;
        return min(b,c)<=k;
    }
};
