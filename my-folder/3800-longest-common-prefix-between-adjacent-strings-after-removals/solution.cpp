class Solution {
public:
    int computeLCP(const string& a, const string& b) {
        int len = min(a.length(), b.length());
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) return i;
        }
        return len;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> lcp(n - 1); // lcp[i] = LCP of words[i] and words[i+1]

        for (int i = 0; i < n - 1; ++i) {
            lcp[i] = computeLCP(words[i], words[i + 1]);
        }

        // Build prefix max and suffix max arrays
        vector<int> prefixMax(n), suffixMax(n);
        for (int i = 1; i < n; ++i)
            prefixMax[i] = max(prefixMax[i - 1], lcp[i - 1]);

        for (int i = n - 2; i >= 0; --i)
            suffixMax[i] = max(suffixMax[i + 1], lcp[i]);

        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            int leftMax = (i >= 2 ? prefixMax[i - 1] : 0);
            int rightMax = (i + 2 <= n ? suffixMax[i + 1] : 0);
            int newLCP = 0;

            if (i > 0 && i < n - 1) {
                newLCP = computeLCP(words[i - 1], words[i + 1]);
            }

            answer[i] = max({leftMax, rightMax, newLCP});
        }

        return answer;
    }
};

