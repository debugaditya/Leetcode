class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int sum1=((n*n)*((n*n)+1))/2;
        vector<int>ans;
        unordered_set<int>st;
        for(auto it:grid){
            for(auto it1:it){
                if(st.find(it1)!=st.end()) ans.push_back(it1);
                else sum1-=it1;
                st.insert(it1);
            }
        }
        ans.push_back(sum1);
        return ans;
    }
};
