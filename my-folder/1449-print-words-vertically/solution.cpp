class Solution {
public:
    vector<string> printVertically(string s) {
        int cnt=0,maxi=0;
        for(auto it:s){
            if(it==' ') {maxi=max(cnt,maxi); cnt=0;}
            else cnt++;
        }maxi=max(cnt,maxi);
        vector<string>ans(maxi,""); int i=0;
        for(auto it:s){
            if(it==' '){while(i<maxi) {ans[i]+=' '; i++;} i=0;}
            else {ans[i]+=it;i++;}
        }
        for(auto &it:ans) while(it.back()==' ') it.pop_back();
        return ans;
    }
};
