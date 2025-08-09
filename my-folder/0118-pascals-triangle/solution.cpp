class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>v={{1}};
        for(int i=2;i<=n;i++){
            vector<int>row(i);
            for(int j=0;j<row.size();j++){
                if(j==i-1||j==0) row[j]=1;
                else row[j]=v.back()[j]+v.back()[j-1];
            }
            v.push_back(row);
        }
        return v;
    }
};
