#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        // Build a frequency map for all characters in words2
        unordered_map<char, int> target_freq;
        for (const string& word : words2) {
            unordered_map<char, int> word_freq;
            for (char c : word) {
                word_freq[c]++;
                target_freq[c] = max(target_freq[c], word_freq[c]);
            }
        }

        // Check each word in words1
        for (const string& word : words1) {
            unordered_map<char, int> word_freq;
            for (char c : word) {
                word_freq[c]++;
            }
            
            bool is_subset = true;
            for (const auto& [c, count] : target_freq) {
                if (word_freq[c] < count) {
                    is_subset = false;
                    break;
                }
            }

            if (is_subset) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
