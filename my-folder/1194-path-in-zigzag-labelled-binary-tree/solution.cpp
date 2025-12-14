class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;
        while(true){
            ans.push_back(label); if(label==1) break;
            int lvl=log2(label),l=pow(2,lvl),r=2*l-1;
            label=(l+r-label)/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
