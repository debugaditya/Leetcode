class Solution {
public:
    int maxDistinct(string s) {
        int ans=0; unordered_set<int>st;
        for(auto it:s){
            if(!st.count(it)) ans++;
            st.insert(it);
        }
        return ans==0?1:ans;
    }
};
