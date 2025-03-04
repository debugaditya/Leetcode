class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false;  // If a digit in base 3 is 2, return false
            n /= 3;  // Reduce n to its base-3 form
        }
        return true;
    }
};

