class Solution {
public:
    string smallestSubsequence(string s) {
        vector<vector<int>>mp(26); set<int>st; string ans="";
        for(int i=0;i<s.size();i++) {mp[s[i]-'a'].push_back(i); st.insert(s[i]-'a');}
        int prev=-1;
        while(st.size()>0){
            for(auto &it:st){
                bool add=true;
                int id=upper_bound(mp[it].begin(),mp[it].end(),prev)-mp[it].begin();
                int i=mp[it][id];
                for(auto it1:st){
                    if(it==it1) continue;
                    int idx=upper_bound(mp[it1].begin(),mp[it1].end(),i)-mp[it1].begin();
                    if(idx==mp[it1].size()) {add=false; break;}
                }
                if(add){
                    ans+=it+'a'; prev=i;
                    st.erase(it);
                    break;
                }
            }
        }
        return ans;
    }
};
