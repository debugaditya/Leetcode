class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int ve, int maxi, int maxid) {
        vector<pair<int,int>>v;
        vector<int>ans;
        for(auto it:r){
            if(it[3]>maxi||it[4]>maxid) continue;
            if(ve==1&&it[2]==1) v.push_back({it[1],it[0]});
            else if(ve==0) v.push_back({it[1],it[0]});
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--) ans.push_back(v[i].second);
        return ans;
    }
};
