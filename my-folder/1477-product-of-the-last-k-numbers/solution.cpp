class ProductOfNumbers {
public:
    vector<int>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
        if(num==0) v.clear();
    }
    
    int getProduct(int k) {
        int ans=1;
        if(v.size()<k) return 0;
        for(int i=0;i<k;i++){
            ans*=v[v.size()-i-1];
        }
        return ans;
    }
};


