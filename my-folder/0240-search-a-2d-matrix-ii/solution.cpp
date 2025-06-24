class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &it:matrix) for(auto &it1:it) if(it1==target) return true;
        return false;
    }
};
