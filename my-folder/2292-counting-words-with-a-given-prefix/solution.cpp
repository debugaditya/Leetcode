class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int ans=0;
        for(auto it:words){
            if(pref==it.substr(0,n)) ans++;
        }
        return ans;
    }
};
