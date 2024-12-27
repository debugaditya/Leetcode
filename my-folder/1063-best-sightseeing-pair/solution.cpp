class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi1 = INT_MIN; // The best value[i] + i so far
        int maxScore = INT_MIN;

        for (int j = 0; j < values.size()-1; j++) {
            // Caulate the potential score for pair (i, j)
            maxi1 = max(maxi1, values[j] + j);
            maxScore = max(maxScore, maxi1 + values[j+1] - j-1);

            // Update maxi1 to be the best value[i] + i up to this point
           
        }

        return maxScore;
    }
};

