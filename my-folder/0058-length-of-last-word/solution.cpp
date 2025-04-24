class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt =0;
        int ans=0;
        for(auto it:s){
            if(it==' ') cnt=0;
            else{
                cnt++;
                ans=cnt;
            }
        }
        return ans;
    }
};
