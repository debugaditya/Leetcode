class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int ans=0;
        vector<int>a;
        for(int i=0;i<queries.size();i++){
            if(mp1[queries[i][1]]==0) ans++;
            mp1[queries[i][1]]++;
            mp1[mp2[queries[i][0]]]--;
            if(mp1[mp2[queries[i][0]]]==0) ans--;
            mp2[queries[i][0]] =queries[i][1];
            a.push_back(ans);
        }
        return a;
    }
};
