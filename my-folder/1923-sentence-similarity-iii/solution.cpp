class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1, s2;
        int l = 0, m = 0;
        
        // Split sentence1 into words
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == ' ') {
                s1.push_back(string(sentence1.begin() + l, sentence1.begin() + i));
                l = i + 1;
            }
        }
        s1.push_back(string(sentence1.begin() + l, sentence1.end()));  // Last word
        
        // Split sentence2 into words
        for (int j = 0; j < sentence2.size(); j++) {
            if (sentence2[j] == ' ') {
                s2.push_back(string(sentence2.begin() + m, sentence2.begin() + j));
                m = j + 1;
            }
        }
        s2.push_back(string(sentence2.begin() + m, sentence2.end()));  // Last word
        
        // Ensure s1 is the larger vector
        if (s1.size() < s2.size()) {
            swap(s1, s2);  // s1 should always be the larger or equal size
        }
        
        // Matching prefix
        int l2 = 0;                
        while (l2 < s2.size() && s1[l2] == s2[l2]) {
            l2++;
        }
        
        // Matching suffix
        int r = s1.size() - 1;      // End of s1
        int r2 = s2.size() - 1;     // End of s2
        while (r2 >= l2 && s1[r] == s2[r2]) {
            r--;
            r2--;
        }
        
        // If we covered the entire smaller sentence (s2) between prefix and suffix
        return (r2 < l2);
    }
};

