class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize an adjacency matrix for reachability
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // Step 2: Mark direct prerequisites
        for (const auto& edge : prerequisites) {
            reachable[edge[0]][edge[1]] = true;
        }

        // Step 3: Floyd-Warshall Algorithm for transitive closure
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        // Step 4: Answer the queries
        vector<bool> ans;
        for (const auto& query : queries) {
            ans.push_back(reachable[query[0]][query[1]]);
        }

        return ans;
    }
};

