class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            vector<int>temp;
            for(auto it:nums){
                if((it&(1<<i))==0) continue;
                if(temp.empty()||temp.back()<it) temp.push_back(it);
                else{
                    int idx=lower_bound(temp.begin(),temp.end(),it)-temp.begin();
                    temp[idx]=it;
                }
            }
            ans=max(ans,(int)temp.size());
        }
        return ans;
    }
};
