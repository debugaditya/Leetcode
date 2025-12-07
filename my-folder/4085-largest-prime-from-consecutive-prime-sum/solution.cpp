class Solution {
public:
    vector<int> get(int n){
        vector<int>ans,v(n+1,0);
        for(int i=2;i<v.size();i++){
            if(v[i]==0){
                ans.push_back(i);
                for(int j=i;j<v.size();j+=i) v[j]=1;
            }
        }
        return ans;
    }
    int largestPrime(int n) {
        if(n<=1) return 0;
        vector<int>p=get(n); unordered_set<int>st(p.begin(),p.end()); int ans=0,sum=0;
        for(auto it:p){
            if(ans<=n&&st.count(ans)) {sum=max(ans,sum);}
            if(ans<=n) ans+=it;
        }
        if(ans<=n&&st.count(ans)) {sum=max(ans,sum); }
        return sum;
    }
};
