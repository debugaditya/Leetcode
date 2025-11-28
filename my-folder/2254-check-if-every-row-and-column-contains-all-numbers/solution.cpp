class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            unordered_set<int>st1(matrix[i].begin(),matrix[i].end()),st2;
            for(int j=1;j<=matrix.size();j++) if(!st1.count(j)) return false;
        }
        for(int i=0;i<matrix.size();i++){
            unordered_set<int>st1;
            for(int j=0;j<matrix.size();j++) st1.insert(matrix[j][i]);
            for(int j=1;j<=matrix.size();j++) if(!st1.count(j)) return false;
        }
        return true;
    }
};
