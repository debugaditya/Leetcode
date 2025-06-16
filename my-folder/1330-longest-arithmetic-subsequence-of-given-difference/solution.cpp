class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>len;
        int ans=0;
        for(auto it:arr){
            len[it]=len[it-diff]+1;
            ans=max(ans,len[it]);
        }
        return ans;
    }
};
