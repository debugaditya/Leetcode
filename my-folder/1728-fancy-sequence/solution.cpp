class Fancy {
public:
    int MOD=1e9+7;
    vector<long long>v;
    long long add=0,mul=1;
    int power(long long a,long long b){
        if(b==1) return a%MOD; if(b==0) return 1;
        long long ans=power(a,b/2);
        ans=ans*ans%MOD; 
        if(b%2==1) ans=ans*a%MOD;
        return ans;
    }
    Fancy() {
        
    }
    
    void append(int val) {
        v.push_back((val-add+MOD)*power(mul,MOD-2)%MOD);
    }
    
    void addAll(int inc) {
        add=add+inc%MOD;
    }
    
    void multAll(int m) {
        mul=mul*m%MOD;
        add=add*m%MOD;
    }
    
    int getIndex(int idx) {
        if(idx>=v.size()) return -1;
        return (v[idx]*mul+add)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
