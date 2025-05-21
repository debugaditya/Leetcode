class Solution {
public:
    int f(vector<vector<int>>&adg,int node,int &cnt){
        if(adg[node].size()==0){
            cnt++;
            return 1;
        }
        int a=f(adg,adg[node][0],cnt);
        int size=a;
        bool d=true;
        for(int i=1;i<adg[node].size();i++){
            int b=f(adg,adg[node][i],cnt);
            size+=b;
            if(a!=b) d=false;
        }
        if(d) cnt++;
        return size+1;
    }
    int countGoodNodes(vector<vector<int>>& e) {
        vector<vector<int>>adg(e.size()+1);
        unordered_set<int>st={0};
        for(auto it:e){
            if(st.count(it[0])) adg[it[0]].push_back(it[1]);
            else adg[it[1]].push_back(it[0]);
            st.insert(it[0]); st.insert(it[1]);
        }
        int cnt=0;
        f(adg,0,cnt);
        return cnt;
    }
};
