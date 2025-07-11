class Solution {
public:
    int mostBooked(int n, vector<vector<int>>&m) {
        vector<int>cnt(n,0); vector<long long>used(n,-1);
        sort(m.begin(),m.end());
        for(auto it:m){
            long long mini=LLONG_MAX;int index=-1;
            for(int i=0;i<n;i++){
                if(used[i]<mini){
                    mini=used[i];
                    index=i;
                }
                if(used[i]<=it[0]){
                    used[i]=it[1];
                    cnt[i]++; break;
                }
                if(i==n-1){
                    used[index]=1LL*(mini+it[1]-it[0]);
                    cnt[index]++;
                }
            }
        }
        int ans=-1; int maxi=-1;
        for(int i=0;i<n;i++){
            if(cnt[i]>maxi){
                maxi=cnt[i];
                ans=i;
            }
        }
        return ans;
    }
};
