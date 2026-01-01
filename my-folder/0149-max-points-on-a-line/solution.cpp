class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        map<pair<float,float>,int>mp; int ans=0; unordered_map<int,int>hori; 
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                if(p[i][0]==p[j][0]) {hori[p[i][0]]++; ans=max(ans,hori[p[i][0]]); continue;}
                double slope=1.0*(p[i][1]-p[j][1])/(p[i][0]-p[j][0]);
                double c=p[j][1]-slope*p[j][0];
                if(slope==0) slope=0;
                mp[{slope,c}]++; ans=max(ans,mp[{slope,c}]);
            }
        }
        //for(auto it:mp) cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
        for(int i=1;i<=p.size();i++) if(2*ans==i*(i-1)) return i;
        return -1;
    }
};
