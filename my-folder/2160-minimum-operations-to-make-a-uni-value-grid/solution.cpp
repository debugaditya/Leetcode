class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<int> arr;

        // Insert all elements into min-heap and store them in arr
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minh.push(grid[i][j]);
                arr.push_back(grid[i][j]);
            }
        }

        int size = n * m;
        int count = 0, median = 0;

        // Extract the median element using the heap
        while (count <= size / 2) {
            median = minh.top();
            minh.pop();
            count++;
        }

        int remainder = grid[0][0] % x;
        int ans = 0;

        // Compute minimum operations
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] % x != remainder) {
                    return -1;
                }
                ans += abs(median - grid[i][j]) / x;
            }
        }
        return ans;
    }
};

