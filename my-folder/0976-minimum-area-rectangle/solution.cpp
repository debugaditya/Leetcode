class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        vector<vector<int>>X(40001),Y(40001); set<pair<int,int>>st; int ans=INT_MAX;
        for(auto it:points){
            if(X[it[0]].size()>0&&Y[it[1]].size()>0){
                int mini=INT_MAX;
                for(auto it1:X[it[0]]){
                    for(auto it2:Y[it[1]]){
                        if(st.count({it2,it1})){
                            mini=min(mini,abs(it[0]-it2)*abs(it[1]-it1));
                        }
                    }
                }
                ans=min(mini,ans);
            }
            st.insert({it[0],it[1]});
            X[it[0]].push_back(it[1]);
            Y[it[1]].push_back(it[0]);
        }
        return ans==INT_MAX?0:ans;
    }
};
