class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int maxElement = INT_MIN;         // To store the maximum element
        pair<int, int> coordinates;       // To store its coordinates (row, col)

        // Traverse through the 2D array
        for (int i = 0; i < mat.size(); ++i) {
            auto rowMax = max_element(mat[i].begin(), mat[i].end()); // Find max in current row
            if (*rowMax > maxElement) {
                maxElement = *rowMax;                                 // Update max value
                coordinates = {i, rowMax - mat[i].begin()};           // Store coordinates
            }
        }

        // Return coordinates as a vector
        return {coordinates.first, coordinates.second};
    }
};

