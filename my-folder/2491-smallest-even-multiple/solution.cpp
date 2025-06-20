class Solution {
public:
    int smallestEvenMultiple(int n) {
        return max(2*n*(n%2),n);
    }
};
