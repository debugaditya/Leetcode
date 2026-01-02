class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int parity=0; long long ans=0,prev=0;
        for(int i=0;i<nums.size();i++){
            int diff=target[i]-nums[i];
            if(diff==0){parity=0; prev=0; continue;}
            if(parity==0){parity=diff<0?-1:1;}
            if((diff>0&&parity==1)||(diff<0&&parity==-1)){
                diff=abs(diff);
                if(diff>prev) ans+=diff-prev;
                prev=diff;
            }
            else {ans+=abs(diff); prev=abs(diff); parity*=-1;}
        }
        return ans;
    }
};
