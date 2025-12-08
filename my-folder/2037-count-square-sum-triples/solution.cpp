class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                int s = i*i + j*j;
                int k = sqrt(s);
                if (k*k == s && k <= n) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

