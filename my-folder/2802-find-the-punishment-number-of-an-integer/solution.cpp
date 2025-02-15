class Solution {
public:
    bool f(int n, string s, int i, int sum) {
        if (i == s.size()) return sum == n; // Ensure we check only at the end

        int num = 0;
        for (int j = i; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0'); // Extract number dynamically
            if (f(n, s, j + 1, sum + num)) return true;
        }

        return false;
    }

    bool check(int n) {
        int t = n * n;
        string s = to_string(t);
        return f(n, s, 0, 0);
    }

    int punishmentNumber(int n) {
        int z = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i)) z += i * i;
        }
        return z;
    }
};

