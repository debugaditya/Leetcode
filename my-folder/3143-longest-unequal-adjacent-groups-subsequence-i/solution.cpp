class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
        vector<string>ans;
        int maxi=w[0].size();
        string s=w[0];
        for(int i=1;i<w.size();i++){
            if(g[i]==g[i-1]&&w[i].size()>maxi){
                maxi=w[i].size();
                s=w[i];
            }
            else if(g[i]!=g[i-1]){
                ans.push_back(s);
                maxi=w[i].size();
                s=w[i];
            }
        }
        ans.push_back(s);
        return ans;
    }
};
