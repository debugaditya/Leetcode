class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>mp;
        vector<int>v1(mat.size(),0);
        vector<int>v2(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]]=make_pair(i,j);
            }
        }
        for(int i=0;i<arr.size();i++){
            v1[mp[arr[i]].first]++;
            if(v1[mp[arr[i]].first]==mat[0].size()) return i;
            v2[mp[arr[i]].second]++;
            if(v2[mp[arr[i]].second]==mat.size()) return i;
        }
        return -1;
    }
};
