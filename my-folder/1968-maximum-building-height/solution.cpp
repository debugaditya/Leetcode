class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        stack<pair<int,int>>st; st.push({1,0}); int adi=0; stack<int>ans;
        sort(r.begin(),r.end());
        for(int i=0;i<r.size();i++){
            int id=r[i][0],maxi=r[i][1];
            auto [prev_id,prev_h]=st.top();
            int idx=id-prev_id;
            if(prev_h+idx<=maxi) continue;
            int peak_h=(idx+maxi+prev_h)/2;
            if(peak_h>=prev_h){
                st.push({id,maxi});
                ans.push(peak_h);
            }
            else{
                st.pop();
                ans.pop();
                i--;
            }
        }
        while(!ans.empty()){adi=max(adi,ans.top()); ans.pop();}
        auto [prev_id,prev_h]=st.top();
        adi=max(adi,prev_h+n-prev_id);
        return adi;
    }
};
