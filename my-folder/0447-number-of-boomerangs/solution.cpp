class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size();i++){
            unordered_map<double,int>mp;
            for(int j=0;j<points.size();j++){
                double dist=1.0*sqrt((points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                ans+=2*mp[dist]; mp[dist]++;
            }
        }
        return ans;
    }
};
