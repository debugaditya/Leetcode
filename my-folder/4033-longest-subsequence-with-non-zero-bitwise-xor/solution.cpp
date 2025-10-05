class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int bit=0; bool d=true;
        for(auto it:nums) {bit^=it; if(it!=0) d=false;}
        if(d) return 0;
        return bit==0?nums.size()-1:nums.size();
    }
};
