
class Solution {
public:
    int beauty(vector<int> &map) {
        int mf = INT_MIN; 
        int lf = INT_MAX; 
        
        for(int i = 0; i < 26; i++) {
            if(map[i] > 0) {
                if(map[i] > mf) {
                    mf = map[i];
                }
                if(map[i] < lf) {
                    lf = map[i];
                }
            }
        }
        
        return (mf - lf);
    }

    int beautySum(string &s) {
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++) {
            vector<int> map(26, 0);
            for(int j = i; j < s.length(); j++) {
                map[s[j] - 'a']++;
                ans += beauty(map);
            }
        }
        
        return ans;
    }
};
