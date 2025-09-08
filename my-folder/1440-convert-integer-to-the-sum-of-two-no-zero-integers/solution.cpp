class Solution {
public:
    bool check(int n){
        while(n>0){
            if(n%10==0) return true;
            n/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int i=n-1,j=1;
        while(i>=j){
            if(check(i)||check(j)) {i--; j++;}
            else return {i,j};
        }
        return {};
    }
};
