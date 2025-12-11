class RangeFreqQuery {
public:
    unordered_map<int,vector<int>>mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) mp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int v) {
        int idx1=lower_bound(mp[v].begin(),mp[v].end(),left)-mp[v].begin();
        int idx2=upper_bound(mp[v].begin(),mp[v].end(),right)-mp[v].begin();
        return idx2-idx1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
