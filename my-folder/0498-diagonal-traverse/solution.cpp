class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);
        
        int i = 0, j = 0, slope = 1; 
        
        while (ans.size() < m * n) {
            ans.push_back(mat[i][j]);
            
            if (slope == 1) { 
                if (j == n - 1) { 
                    i++;
                    slope = -1;
                } else if (i == 0) { 
                    j++;
                    slope = -1;
                } else { 
                    i--;
                    j++;
                }
            } else { 
                if (i == m - 1) { 
                    j++;
                    slope = 1;
                } else if (j == 0) { 
                    i++;
                    slope = 1;
                } else { 
                    i++;
                    j--;
                }
            }
        }
        
        return ans;
    }
};

