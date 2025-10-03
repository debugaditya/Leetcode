class Solution {
public:
    bool check(vector<int>& c,int h){
        int cnt=0;
        for(auto it:c) if(it>=h) cnt++;
        return cnt>=h;
    }
    int hIndex(vector<int>& c) {
        int l=0,r=c.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(check(c,mid)) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};
