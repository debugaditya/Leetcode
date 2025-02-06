class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(points[0]==points[1]||points[0]==points[2]||points[1]==points[2]) return false;
        if(points[0][0]==points[1][0]&&points[1][0]==points[2][0]) return  false;
        double m1=(points[1][1]-points[0][1])/(double) (points[1][0]-points[0][0]);
        double m2=(points[2][1]-points[1][1])/(double) (points[2][0]-points[1][0]);
        if(m1==m2) return false;
        return true;
    }
};
