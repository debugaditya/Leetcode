class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        unordered_set<int>st; long long ans=-1;
        h.push_back(1); h.push_back(m);
        v.push_back(1); v.push_back(n);
        for(int i=0;i<h.size();i++){
            for(int j=i+1;j<h.size();j++) st.insert(abs(h[i]-h[j]));
        }
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(st.count(abs(v[i]-v[j]))) ans=max(ans,1LL*abs(v[i]-v[j])*abs(v[i]-v[j]));
            }
        }
        if(ans==-1) return -1;
        return ans%1000000007;
    }
};
