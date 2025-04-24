class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index=0;
        string ans="";
        while(true){
            for(auto it:strs) if(index>=it.size()||it[index]!=strs[0][index]) return ans;
            ans+=strs[0][index++];
        }
        return ans;
    }
};
