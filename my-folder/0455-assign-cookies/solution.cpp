class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0;
        int j=0;
        while(i<s.size()&&j<g.size()){
            if(g[j]<=s[i]){
                ans++;
                i++;
                j++;
            }
            else i++;
        }
        return ans;
    }
};
