#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <climits>

class Solution {
public:
    unsigned long long binToUll(const std::string& s) {
        unsigned long long res = 0;
        for (char c : s) {
            if (res > ULLONG_MAX / 2) return ULLONG_MAX;
            res *= 2;
            if (c == '1') {
                if (res > ULLONG_MAX - 1) return ULLONG_MAX;
                res += 1;
            }
        }
        return res;
    }

    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1;
        if (n <= 2) return 2;
        if (n <= 4) return 3;

        long long ans = 0;
        
        for (int L = 1; L <= 64; ++L) {
            unsigned long long power_of_2_L = (L < 63) ? (1ULL << L) : ULLONG_MAX;
            
            unsigned long long n_minus_1_div_2 = (n - 1) / 2;

            if (power_of_2_L > n_minus_1_div_2) {
                break;
            }

            long long limit = n_minus_1_div_2 - power_of_2_L;
            
            int k = (L + 1) / 2;
            long long high = (k > 0) ? (1LL << k) - 1 : 0;
            if (k >= 63) high = LLONG_MAX;

            long long low = 0;
            long long count_for_L = 0;

            while (low <= high) {
                long long mid_val = low + (high - low) / 2;
                
                std::string left = std::bitset<32>(mid_val).to_string();
                if (k < 32) {
                    left = left.substr(32 - k);
                }
                
                std::string right = left;
                if (L % 2 == 1) {
                    right.pop_back();
                }
                std::reverse(right.begin(), right.end());
                std::string s = left + right;

                unsigned long long dec_s = binToUll(s);
                
                if (dec_s <= (unsigned long long)limit) {
                    count_for_L = mid_val + 1;
                    low = mid_val + 1;
                } else {
                    high = mid_val - 1;
                }
            }
            ans += count_for_L;
        }

        return 3 + ans;
    }
};
