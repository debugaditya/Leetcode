class Solution {
public:
    void sor(string &s){
        sort(s.begin(),s.end());
    }
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sor(s); long long num=1;
        for(int i=0;i<32;i++){
            string t=to_string(num); sor(t);
            if(t==s) return true;
            num*=2;
        }
        return false;
    }
};
