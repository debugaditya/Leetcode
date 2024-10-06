#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    // Function to convert an integer to its binary representation as a string
    string toBinary(int num) {
        if (num == 0) return "0";  // Handle the special case for zero

        string binary;
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;  // Prepend the binary digit
            num /= 2;  // Divide the number by 2
        }
        return binary;
    }

    // Function to find the maximum concatenated binary number
    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaryStrings;
        // Convert all numbers to their binary representations
        for (int num : nums) {
            binaryStrings.push_back(toBinary(num));
        }

        int maxNum = 0;
        // Generate all permutations of the binary strings
        sort(binaryStrings.begin(), binaryStrings.end());
        do {
            // Concatenate the binary strings in this permutation
            string concatenated = binaryStrings[0] + binaryStrings[1] + binaryStrings[2];
            // Convert the concatenated binary string to an integer
            int currentNum = stoi(concatenated, nullptr, 2);
            maxNum = max(maxNum, currentNum);  // Update maxNum if the current number is larger
        } while (next_permutation(binaryStrings.begin(), binaryStrings.end()));

        return maxNum;  // Return the maximum number found
    }
};


