class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int cnt=0,i=0,j=0;
        sort(p.begin(),p.end()); sort(t.begin(),t.end());
        while(i<p.size()&&j<t.size()){
            if(t[j]>=p[i]){
                i++; j++;
                cnt++;
            }
            else j++;
        }
        return cnt;
    }
};
