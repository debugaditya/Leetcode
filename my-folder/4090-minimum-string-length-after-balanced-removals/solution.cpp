class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0,b=0;
        for(auto it:s){
            if(it=='a') a++;
            else b++;
        }
        return s.size()-2*min(a,b);
    }
};
