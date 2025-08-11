class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int>st={2,5,7,3,11,13,19,17,23,31,29,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        int f=-1,l=-1;
        for(int i=0;i<nums.size();i++) if(st.count(nums[i])) {if(f==-1) {f=i; l=i;} else l=i;}
        return l-f;
    }
};
