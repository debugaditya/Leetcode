class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int sum=0,points=0;
        for(auto it:p) {if(it==1) sum++; else sum--;}
        for(int i=0;i<p.size()-1;i++) {if(p[i]==1) points++; else points--; if(points>sum-points) return i+1;}
        return -1;
    }
};
