class Solution {
public:
    int divide(long long d1, long long d2) {
        if(d1/d2>=0) return d1/d2>INT_MAX?INT_MAX:d1/d2;
        if(d1/d2<0) return d1/d2<INT_MIN?INT_MIN:d1/d2;
        return 0;
    }
};
