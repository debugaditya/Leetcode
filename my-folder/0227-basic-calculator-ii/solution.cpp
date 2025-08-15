class Solution {
public:
    int calculate(string s) {
        vector<string> a;
        string temp = "";

        // Tokenize
        for (auto it : s) {
            if (it == '+' || it == '*' || it == '/' || it == '-') {
                if (temp != "") {
                    a.push_back(temp);
                    temp = "";
                }
                string f = ""; f += it;
                a.push_back(f);
            }
            else if (it != ' ') temp += it;
        }
        if (temp != "") {
            a.push_back(temp);
        }

        // First pass: handle * and /
        vector<string> b;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == "*" || a[i] == "/") {
                int x = stoi(b.back());
                int y = stoi(a[++i]);
                b.pop_back();
                if (a[i - 1] == "*") b.push_back(to_string(x * y));
                else b.push_back(to_string(x / y));
            }
            else {
                b.push_back(a[i]);
            }
        }

        // Second pass: handle + and -
        int ans = stoi(b[0]);
        for (int i = 1; i < b.size(); i += 2) {
            int y = stoi(b[i + 1]);
            if (b[i] == "+") ans += y;
            else ans -= y;
        }

        return ans;
    }
};

