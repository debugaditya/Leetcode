#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>>& grid, int k, int i, int j, int d, vector<vector<unordered_map<int, int>>>& memo, int mod) {
        // Base case: if out of bounds, return 0
        if (i >= grid.size() || j >= grid[0].size()) return 0;

        // Update the current XOR value
        d ^= grid[i][j];

        // Check if we reached the bottom-right cell
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return d == k ? 1 : 0;
        }

        // Check if the result is already computed
        if (memo[i][j].count(d)) return memo[i][j][d];

        // Recursive calls: move down and right
        int down = f(grid, k, i + 1, j, d, memo, mod);
        int right = f(grid, k, i, j + 1, d, memo, mod);

        // Store the result in memo and return it with modulo
        return memo[i][j][d] = (down + right) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int mod = 1e9 + 7;

        // Create a memoization table
        vector<vector<unordered_map<int, int>>> memo(rows, vector<unordered_map<int, int>>(cols));

        return f(grid, k, 0, 0, 0, memo, mod);
    }
};

