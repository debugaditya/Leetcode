class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>v;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0) v.push_back(i); 
            if(v.size()==k) return i;
        }
        int fact= 2*v.size();
        if(v.back()*v.back()==n) fact--;
        return fact>=k?n/v[fact-k]:-1;
    }
};
