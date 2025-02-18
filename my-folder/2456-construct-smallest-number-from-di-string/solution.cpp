class Solution {
public:
    string f(string pattern, int index, string ans) {
        if(index ==pattern.size()) return ans;
        if (index == -1) {
            string mini = "99999999999";
            for (int i = 1; i <= 9; i++) {
                if (ans.find(to_string(i)) != string::npos)
                    continue;
                string temp = ans;
                temp += to_string(i);
                mini = min(mini, f(pattern, index + 1, temp));
            }
            return mini;
        } else {
            if (pattern[index] == 'I') {
                string mini = "99999999999";
                for (int i = (ans.empty() ? 1 : stoi(string(1, ans.back()))); i <= 9; i++) {
                    if (ans.find(to_string(i)) != string::npos)
                        continue;
                    string temp = ans;
                    temp += to_string(i);
                    mini = min(mini, f(pattern, index + 1, temp));
                }
                return mini;
            } else {
                string mini = "99999999999";
                for (int i = (ans.empty() ? 9 : stoi(string(1, ans.back()))); i >= 1; i--) {
                    if (ans.find(to_string(i)) != string::npos)
                        continue;
                    string temp = ans;
                    temp += to_string(i);
                    mini = min(mini, f(pattern, index + 1, temp));
                }
                return mini;
            }
        }
    }

    string smallestNumber(string pattern) {
        string ans = "";
        return f(pattern, -1, ans);
    }
};
