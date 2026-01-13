class Solution {
public:
    double area(double y,vector<vector<int>>& squares){
        double ans=0;
        for(auto &it:squares) if(y>it[1]) ans+=min(1.0*it[2]*it[2],1.0*(y-it[1])*it[2]);
        return ans;
    }
    double separateSquares(vector<vector<int>>& squares) {
        long long total=0;
        for(auto it:squares) total+=1LL*it[2]*it[2];
        double l=0,r=INT_MAX;
        while(l<=r){
            double mid=l+(r-l)/2.0;
            double below=area(mid,squares);
            if(2*below>=total) r=mid-0.00001;
            else l=mid+0.00001;
        }
        return l;
    }
};
