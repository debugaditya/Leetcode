class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        set<int>st;
        int n=f.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            bool d=false;
            for(int j=0;j<n;j++){
                if(f[i]<=b[j]&&st.find(j)==st.end()){
                    st.insert(j);
                    d=true;
                    break;
                }
            }
            if(!d) cnt++;
        }
        return cnt;
    }
};
