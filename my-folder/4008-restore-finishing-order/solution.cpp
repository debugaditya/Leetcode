class Solution {
public:
    bool search(int it, vector<int>& f){
        int l=0,r=f.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(f[mid]==it) return true;
            else if(f[mid]>it) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    vector<int> recoverOrder(vector<int>& o, vector<int>& f) {
        vector<int>ans;
        for(auto it:o) if(search(it,f)) ans.push_back(it);
        return ans;
    }
};
