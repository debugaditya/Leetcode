class Solution {
public:
    int maxFreeTime(int e, int k, vector<int>& s, vector<int>& end) {
        vector<int>br; br.push_back(s[0]-0); int ans=0,sum=0;
        for(int i=1;i<s.size();i++) br.push_back(s[i]-end[i-1]);
        br.push_back(e-end.back());
        for(int i=0;i<br.size();i++){
            if(i<=k) sum+=br[i];
            else{
                sum+=br[i];
                sum-=br[i-k-1];
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};
