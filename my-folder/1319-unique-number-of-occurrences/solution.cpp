class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>v1(2001,0);
        unordered_set<int>st;
        for(auto it:arr) v1[it+1000]++;
        for(auto it:v1){
            if(it==0) continue;
            if(st.find(it)!=st.end()) return false;
            st.insert(it);
        }
        return true;
    }
};
