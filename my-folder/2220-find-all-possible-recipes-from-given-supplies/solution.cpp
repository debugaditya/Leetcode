class Solution {
public:
    unordered_map<string, bool> memo;  // Store results of computed recipes
    unordered_set<string> visited;  // Detect cycles

    bool canMake(unordered_set<string>& supply, string recipe, unordered_map<string, vector<string>>& mp) {
        if (supply.find(recipe) != supply.end()) return true;  // Directly available
        if (memo.find(recipe) != memo.end()) return memo[recipe];  // Use cached result
        if (visited.find(recipe) != visited.end()) return false;  // Cycle detected
        if (mp.find(recipe) == mp.end()) return false;  // Recipe not found

        visited.insert(recipe);  // Mark as visited (for cycle detection)

        bool possible = true;
        for (const auto& ingredient : mp[recipe]) {
            if (!canMake(supply, ingredient, mp)) {
                possible = false;
                break;
            }
        }

        visited.erase(recipe);  // Unmark to allow fresh calls in different paths
        return memo[recipe] = possible;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supply(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> mp;
        vector<string> ans;

        // Build recipe dependency graph
        for (int i = 0; i < recipes.size(); i++) {
            mp[recipes[i]] = ingredients[i];
        }

        // Process each recipe using memoized DFS
        for (const auto& recipe : recipes) {
            if (canMake(supply, recipe, mp)) ans.push_back(recipe);
        }

        return ans;
    }
};

