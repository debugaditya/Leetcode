class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size(),ans=0; vector<string>v(strs.size());
        for(int i=0;i<n;i++){
            for(int j=0;j<v.size();j++) v[j]+=strs[j][i];
            for(int j=1;j<v.size();j++){
                if(v[j-1]>v[j]){
                    ans++;
                    for(int k=0;k<v.size();k++) v[k].pop_back();
                    break; 
                }
            }
        }
        return ans;
    }
};
