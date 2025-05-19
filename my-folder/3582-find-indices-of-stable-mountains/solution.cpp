class Solution {
public:
    vector<int> stableMountains(vector<int>& h, int t) {
        vector<int>v;
        for(int i=1;i<h.size();i++) if(h[i-1]>t) v.push_back(i);
        return v;
    }
};
