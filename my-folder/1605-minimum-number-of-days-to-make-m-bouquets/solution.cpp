class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        // If it's impossible to form m bouquets, return -1
        

        // Find the minimum and maximum bloom days
        int low = *min_element(bloom.begin(), bloom.end());
        int high = *max_element(bloom.begin(), bloom.end());
        int ans = -1;

        // Binary search for the minimum day
        while (low <= high) {
            int mid = (high + low) / 2;

            int bouquet = 0;  // Number of bouquets formed
            int counter = 0;  // Count of consecutive flowers ready

            for (int days : bloom) {
                if (days <= mid) {
                    counter++;
                    if (counter == k) {
                        bouquet++;
                        counter = 0;  // Reset after forming a bouquet
                    }
                } else {
                    counter = 0;  // Reset if flower isn't ready
                }

                if (bouquet >= m) break;  // Early exit if condition met
            }

            // Adjust binary search range
            if (bouquet >= m) {
                ans = mid;
                high = mid - 1;  // Look for a smaller day
            } else {
                low = mid + 1;  // Look for a larger day
            }
        }

        return ans;
    }
};

