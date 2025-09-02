class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                bool d=true;
                if(i==j) continue;
                if(!(points[i][0] <= points[j][0] && points[i][1] >= points[j][1])) continue;
                int minix=min(points[i][0],points[j][0]),miniy=min(points[i][1],points[j][1]),maxix=max(points[i][0],points[j][0]),maxiy=max(points[i][1],points[j][1]);
                for(auto it:points){
                    if(it[0]==points[i][0]&&it[1]==points[i][1]) continue;
                    if(it[0]==points[j][0]&&it[1]==points[j][1]) continue;
                    if(it[0]>=minix&&it[0]<=maxix&&it[1]>=miniy&&it[1]<=maxiy) {d=false; break;}
                }
                if(d) cnt++;
            }
        }
        return cnt;
    }
};
