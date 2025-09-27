class Solution {
public:
    double area(vector<int>&p1,vector<int>&p2,vector<int>&p3){
        double dist1,dist2,dist3;
        dist1=1.0*sqrt(abs(p2[0]-p1[0])*abs(p2[0]-p1[0])+abs(p2[1]-p1[1])*abs(p2[1]-p1[1]));
        dist2=1.0*sqrt(abs(p2[0]-p3[0])*abs(p2[0]-p3[0])+abs(p2[1]-p3[1])*abs(p2[1]-p3[1]));
        dist3=1.0*sqrt(abs(p3[0]-p1[0])*abs(p3[0]-p1[0])+abs(p3[1]-p1[1])*abs(p3[1]-p1[1]));
        double avg=1.0*(dist1+dist2+dist3)/2;
        return 1.0*(sqrt(avg*(avg-dist1)*(avg-dist2)*(avg-dist3)));
    }
    double largestTriangleArea(vector<vector<int>>& p) {
        double ans=0;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                for(int k=j+1;k<p.size();k++){
                    ans=max(ans,area(p[i],p[j],p[k]));
                }
            }
        }
        return ans;
    }
};
