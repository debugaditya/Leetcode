class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;

        int l = 0, r = n - 1; // Two pointers for traversal
        int balanceL = 0, unlockedL = 0; // Left-to-right tracking
        int balanceR = 0, unlockedR = 0; // Right-to-left tracking

        while (l < n && r >= 0) {
            // Left-to-right traversal
            if (locked[l] == '1') {
                if (s[l] == '(') balanceL++; // Count '('
                else { // For ')'
                    if (balanceL > 0) balanceL--;
                    else if (unlockedL > 0) unlockedL--; // Use unlocked to balance
                    else return false;
                }
            } else {
                unlockedL++; // Track unlocked characters
            }

            // Right-to-left traversal
            if (locked[r] == '1') {
                if (s[r] == ')') balanceR++; // Count ')'
                else { // For '('
                    if (balanceR > 0) balanceR--;
                    else if (unlockedR > 0) unlockedR--; // Use unlocked to balance
                    else return false;
                }
            } else {
                unlockedR++; // Track unlocked characters
            }

            // Move pointers
            l++;
            r--;
        }

        // Check if all unmatched parentheses can be balanced
        return (balanceL <= unlockedL && (balanceL + unlockedL) % 2 == 0) &&
               (balanceR <= unlockedR && (balanceR + unlockedR) % 2 == 0);
    }
};

