class Solution {
public:
    string longestPrefix(string s) {
        int l=0;
        int r=s.size()-2;
        int l2=1;
        int r2=s.size()-1;
        string s1=s.substr(l,r-l+1);
        string s2=s.substr(l2,r2-l2+1);
        while(r>=0){
            if(s1==s2){
                return s1;
            }
            else{
                s2.erase(0, 1); 
                s1.pop_back();
            }
        }
        string s3="";
        return s3;
    }
};
