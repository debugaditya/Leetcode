class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int maxi) {
        vector<string> ans;
        vector<int> v;
        map<int, int> hash;
        int sum = 0;
        v.push_back(-1);
        
        for (int i = 0; i < w.size(); i++) {
            sum += w[i].size() + 1;
            hash[i] = sum;
            if (sum <= maxi + 1) continue;
            else {
                v.push_back(i - 1);
                sum = w[i].size() + 1;
            }
        }
        
        v.push_back(w.size() - 1);
        
        for (int i = 1; i < v.size(); i++) {
            int gaps = v[i] - v[i-1] - 1;
            int word_length = 0;
            
            for (int j = v[i-1] + 1; j <= v[i]; j++) {
                word_length += w[j].size();
            }
            
            int spaces = maxi - word_length;
            
            if (gaps == 0 || v[i] == w.size()-1) { // single word or last line
                string s = w[v[i-1]+1];
                for (int j = v[i-1]+2; j <= v[i]; j++) {
                    s += ' ';
                    s += w[j];
                }
                while (s.size() < maxi) s += ' ';
                ans.push_back(s);
            }
            else {
                string s = w[v[i-1]+1];
                int ext = spaces % gaps;
                int normal = spaces / gaps;
                
                for (int j = v[i-1]+2; j <= v[i]; j++) {
                    for (int k = 0; k < normal; k++) s += ' ';
                    if (ext > 0) {
                        s += ' ';
                        ext--;
                    }
                    s += w[j];
                }
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};

