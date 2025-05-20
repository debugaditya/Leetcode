class Solution {
public:
    int sumImbalanceNumbers(vector<int>& n) {
        vector<vector<int>> ans(n.size(), vector<int>(n.size(), 0));
        int sum = 0;
        for (int i = 0; i < n.size(); i++) {
            vector<int> temp = {n[i]};
            for (int j = i + 1; j < n.size(); j++) {
                for (int k = 0; k <= temp.size(); k++) {
                    if (k == temp.size() || temp[k] >= n[j]) {
                        if (k == 0) {
                            ans[i][j] = ans[i][j-1] + (temp[0] - n[j] > 1 ? 1 : 0);
                        }
                        else if (k == temp.size()) {
                            ans[i][j] = ans[i][j-1] + (n[j] - temp.back() > 1 ? 1 : 0);
                        }
                        else {
                            if (temp[k] - temp[k-1] > 1) {
                                if (temp[k] - n[j] > 1 && n[j] - temp[k-1] > 1) {
                                    ans[i][j] = ans[i][j-1] + 1;
                                }
                                else if (temp[k] - n[j] <= 1 && n[j] - temp[k-1] <= 1) {
                                    ans[i][j] = ans[i][j-1] - 1;
                                }
                                else {
                                    ans[i][j] = ans[i][j-1];
                                }
                            }
                            else {
                                ans[i][j] = ans[i][j-1];
                            }
                        }
                        temp.insert(temp.begin() + k, n[j]);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n.size(); i++) {
            for (int j = i + 1; j < n.size(); j++) {
                sum += ans[i][j];
            }
        }
        return sum;
    }
};
