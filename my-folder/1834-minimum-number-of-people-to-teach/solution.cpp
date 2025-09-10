class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        unordered_set<int>st(a.begin(),a.end());
        for(auto it:b) if(st.count(it)) return true;
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
        vector<vector<int>>f2; vector<int>mp(n+1,0); unordered_set<int>st; int maxi=0; vector<int>lang; int cnt=0;
        for(auto it:f) if(!check(l[it[0]-1],l[it[1]-1])) f2.push_back(it);
        for(auto it:f2) {st.insert(it[0]); st.insert(it[1]);}
        for(auto it:st) for(auto it1:l[it-1]){mp[it1]++; if(maxi<mp[it1]) maxi=mp[it1];}
        for(int i=0;i<mp.size();i++) if(mp[i]==maxi) lang.push_back(i); 
        for(auto la:lang){
            int c=0;
            for(auto it:st) {
                for(auto it1:l[it-1]){
                    if(it1==la) c++;
                }
            }
            cnt=max(cnt,c);
        }  
        return st.size()-cnt;
    }
};
