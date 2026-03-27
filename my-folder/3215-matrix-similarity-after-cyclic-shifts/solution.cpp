class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int even=1; int dup;
        for(auto &it:mat){
            dup=k%it.size();
            if(even) {for(int i=0;i<it.size();i++) {if(it[i]!=it[(i+dup)%it.size()]) return false;}}
            else {for(int i=0;i<it.size();i++) {if(it[i]!=it[(i-dup+it.size())%it.size()]) return false;}}
            even=1-even;
        }
        return true;
    }
};
