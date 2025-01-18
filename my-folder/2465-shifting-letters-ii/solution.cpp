class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftEffect(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                shiftEffect[start] += 1;
                shiftEffect[end + 1] -= 1;
            } else {
                shiftEffect[start] -= 1;
                shiftEffect[end + 1] += 1;
            }
        }

        // Compute the prefix sum to get the net effect on each character
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += shiftEffect[i];
            int shiftValue = (s[i] - 'a' + netShift) % 26;
            if (shiftValue < 0) shiftValue += 26; // Handle negative shifts
            s[i] = 'a' + shiftValue;
        }

        return s;
    }
};

