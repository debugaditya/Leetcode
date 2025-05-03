class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& bu) {
        vector<int>a(n+1,INT_MIN);
        vector<int>b(n+1,INT_MAX);
        vector<int>c(n+1,INT_MIN);
        vector<int>d(n+1,INT_MAX);
        int cnt=0;
        for(auto it:bu){
            a[it[0]]=max(a[it[0]],it[1]);
            b[it[0]]=min(b[it[0]],it[1]);
            c[it[1]]=max(c[it[1]],it[0]);
            d[it[1]]=min(d[it[1]],it[0]);
        }
        for(auto it:bu) if(a[it[0]]!=it[1]&&b[it[0]]!=it[1]&&c[it[1]]!=it[0]&&d[it[1]]!=it[0]) cnt++;
        return cnt;
    }
};
