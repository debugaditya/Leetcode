class Solution {
public:
    int numberOfChild(int n, int k) {
        return min(k%(2*(n-1)),2*(n-1)-k%(2*(n-1)));
    }
};
