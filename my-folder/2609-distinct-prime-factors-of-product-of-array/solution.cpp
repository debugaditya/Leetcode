class Solution {
public:
    vector<int>pq; unordered_set<int>st;
    void getprimes(int n){
        vector<int>v(n+1,0);
        for(int i=2;i<v.size();i++){
            if(v[i]==0) pq.push_back(i);
            for(int j=i;j<v.size();j+=i) v[j]=1;
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end()); getprimes(maxi);
        for(auto it:nums) for(int i=0;i<pq.size();i++) if(it%pq[i]==0) st.insert(pq[i]);
        return st.size();
    }
};
