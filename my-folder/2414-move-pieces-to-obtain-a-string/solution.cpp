class Solution {
public:
    bool canChange(string start, string target) {
        vector<int>l1;
        vector<int>r1;
        vector<int>l2;
        vector<int>r2;
        string s="";
        string t="";
        for(int i=0;i<start.size();i++){
            if(target[i]=='R'){
                t+=target[i];
                r2.push_back(i);
            }
            if(start[i]=='L'){
                s+=start[i];
                l1.push_back(i);
            }
            if(target[i]=='L'){
                t+=target[i];
                l2.push_back(i);
            }
            if(start[i]=='R'){
                s+=start[i];
                r1.push_back(i);
            }
        }
        if(s!=t){
            return false;
        }
        int n=max(l1.size(),r1.size());
        for(int i=0;i<n;i++){
            if(i<l1.size()){
                if(l1[i]<l2[i]){
                    return false;
                }
            }
            if(i<r1.size()){
                if(r1[i]>r2[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
