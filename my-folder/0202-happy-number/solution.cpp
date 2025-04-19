class Solution {
public:
    bool isHappy(int n) {
        set<int>st;
        while(n>1){
            int sum=0;
            while(n>0){
                sum+=pow(n%10,2);
                n/=10;
            }
            n=sum;
            if(st.find(sum)!=st.end()) return false;
            st.insert(sum);
        }
        return true;
    }
};
