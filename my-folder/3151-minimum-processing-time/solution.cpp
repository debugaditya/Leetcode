class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end()); sort(t.begin(),t.end()); int j=0,ans=0;
        for(int i=t.size()-1;i>=0;i-=4){
            ans=max(ans,t[i]+p[j]);
            j++;
        }
        return ans;
    }
};
