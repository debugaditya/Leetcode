class Solution {
public:
    string convertToTitle(int col) {
        string ans="";
        while(col>0){
            col--;
            ans.insert(ans.begin(),col%26+'A');
            col/=26;
        }
        return ans;
    }
};
