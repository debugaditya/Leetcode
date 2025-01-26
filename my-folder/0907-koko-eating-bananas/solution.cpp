class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid=(l+r)/2;
            long long a=0;
            for(auto it:piles) {
                a+=ceil((double)it/mid);
                if(a>h) break;
            }
            if(a<=h) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
