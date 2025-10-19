class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end()); int i=k;
        while(true){
            if(!st.count(i)) return i;
            i+=k;
        }
        return -1;
    }
};
