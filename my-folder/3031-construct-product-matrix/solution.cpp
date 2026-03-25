class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int>v;
        for(auto it:grid) for(auto it1:it) v.push_back(it1);
        int sz = v.size(),k=0; vector<int> prefix(sz, 1), suffix(sz, 1);
        for(int i=1;i<sz;i++) prefix[i]=1LL*v[i-1]*prefix[i-1]%12345;
        for(int i=sz-2;i>=0;i--) suffix[i]=1LL*v[i+1]*suffix[i+1]%12345;
        for(auto &it:grid) for(auto &it1:it) {it1=1LL*prefix[k]*suffix[k]%12345; k++;}
        return grid;
    }
};
