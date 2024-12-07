class Solution {
public:
    int minimumSize(vector<int>& nu, int ma) {
        int l=1,h=*max_element(nu.begin(),nu.end());
        while(l<h){
            int m=l+(h-l)/2;
            int o=0;
            for(int n:nu)if((o+=(n-1)/m)>ma)break;
            o<=ma?h=m:l=m+1;
        }return h;
    }
};
