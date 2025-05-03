class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int cnt1=1,cnt2=0,cnt3=0,cnt4=1,n=t.size();
        unordered_set<int>st={t[0],b[0]};
        for(int i=1;i<n;i++){
            if(t[0]!=t[i]&&t[0]!=b[i]) st.erase(t[0]);
            if(b[0]!=t[i]&&b[0]!=b[i]) st.erase(b[0]);
            if(st.empty()) return -1;
            if(t[0]==t[i]) cnt1++;
            if(t[0]==b[i]) cnt2++;
            if(b[0]==t[i]) cnt3++;
            if(b[0]==b[i]) cnt4++;
        }
        return min({n-cnt1,n-cnt2,n-cnt3,n-cnt4});
    }
};
