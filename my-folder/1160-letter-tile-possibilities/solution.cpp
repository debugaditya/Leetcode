#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    void f(string& tiles, vector<bool>& used, string s, set<string>& st) {
        if (!s.empty()) st.insert(s);  // Store valid sequences
        
        for (int i = 0; i < tiles.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                f(tiles, used, s + tiles[i], st);
                used[i] = false;  // Backtrack
            }
        }
    }

    int numTilePossibilities(string tiles) {
        set<string> st;
        vector<bool> used(tiles.size(), false);  // Track used tiles
        f(tiles, used, "", st);
        return st.size();
    }
};




