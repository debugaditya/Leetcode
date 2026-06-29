class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end()); int cnt=0,maxi=INT_MIN,curr=p.back()[1];
        for(int i=p.size()-2;i>=0;i--){
            if(p[i][0]!=p[i+1][0]) {maxi=max(curr,maxi); curr=p[i][1];}
            else curr=max(curr,p[i][1]);
            if(maxi>p[i][1]) cnt++;
        }
        return cnt;
    }
};
