class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n>0){
            ans*=10; ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &it:nums) {st.insert(it); st.insert(reverse(it));}
        return st.size();
    }
};
