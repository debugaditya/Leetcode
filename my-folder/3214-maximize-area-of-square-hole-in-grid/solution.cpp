class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        int cnt1=0,maxi1=0,cnt2=0,maxi2=0;
        sort(h.begin(),h.end()); sort(v.begin(),v.end());
        for(int i=0;i<h.size();i++){
            if(h[i]==1||h[i]==n+2) continue;
            if(i==0||h[i]==h[i-1]+1) cnt1++;
            else {maxi1=max(cnt1,maxi1); cnt1=1;}
        }
        maxi1=max(cnt1,maxi1);
        for(int i=0;i<v.size();i++){
            if(v[i]==1||v[i]==m+2) continue;
            if(i==0||v[i]==v[i-1]+1) cnt2++;
            else {maxi2=max(cnt2,maxi2); cnt2=1;}
        }
        maxi2=max(cnt2,maxi2);
        return min(maxi1+1,maxi2+1)*min(maxi1+1,maxi2+1);
    }
};
