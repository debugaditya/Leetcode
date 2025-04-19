class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>v(n,0);
        long long sum=0;
        for(auto it:roads){
            v[it[0]]++;
            v[it[1]]++;
        }
        sort(v.begin(),v.end());
        
        for(int i=n-1;i>=0;i--) sum+=1LL*(i+1)*v[i];
        return sum;
    }
};
