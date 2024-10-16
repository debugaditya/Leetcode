class Solution {
public:
    long long minimumSteps(string s) {
        vector<int> v0;
        vector<int> v1;
        int cnt0 = 0;
        
        // Count the number of '0's in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt0++;
            }
        }
        
        // Identify the positions of misplaced '1's and '0's
        for (int j = 0; j < cnt0; j++) {
            if (s[j] == '1') {
                v1.push_back(j);
            }
        }
        for (int j = cnt0; j < s.size(); j++) {
            if (s[j] == '0') {
                v0.push_back(j);
            }
        }

        // The number of misplaced pairs should be the same for v0 and v1
        int ss = min(v0.size(), v1.size());
        long long ans = 0;

        // Calculate the total number of swaps required
        for (int t = 0; t < ss; t++) {
            // The distance each '1' needs to move to reach the position of the '0'
            ans += v0[t] - v1[t];
        }
        
        return ans;
    }
};

