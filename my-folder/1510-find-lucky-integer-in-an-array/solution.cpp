class Solution {
public:
    int findLucky(vector<int>& arr) {
        set<int>st; vector<int>mp(501,0);
        for(auto it:arr){
            mp[it]++;
            if(mp[it]==it) st.insert(it);
            if(mp[it]==it+1) st.erase(it);
        }
        if(st.size()==0) return -1;
        return *--st.end();
    }
};
