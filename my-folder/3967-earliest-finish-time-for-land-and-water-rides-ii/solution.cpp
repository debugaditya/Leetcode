class Solution {
public:
    int earliestFinishTime(vector<int>& lt, vector<int>& ld, vector<int>& wt, vector<int>& wd) {
        vector<int>wet,let; int ans=INT_MAX;
        for(int i=0;i<lt.size();i++) let.push_back(lt[i]+ld[i]); sort(let.begin(),let.end());
        for(int i=0;i<wt.size();i++) wet.push_back(wt[i]+wd[i]); sort(wet.begin(),wet.end());
        for(int i=0;i<lt.size();i++){
            if(wet[0]<=lt[i]) ans=min(ans,lt[i]+ld[i]);
            else ans=min(ans,wet[0]+ld[i]);
        }
        for(int i=0;i<wt.size();i++) {
            if(let[0]<=wt[i]) ans=min(ans,wt[i]+wd[i]); 
            else ans=min(ans,let[0]+wd[i]);
        }
        return ans;
    }
};
