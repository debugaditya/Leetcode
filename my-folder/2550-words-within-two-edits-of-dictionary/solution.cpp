class Solution {
public:
    bool check(string a,string b){
        if(a.size()!=b.size()) return false; int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) cnt++;
            if(cnt==3) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto it:queries) for(auto it1:dictionary) if(check(it,it1)){ans.push_back(it); break;}
        return ans;
    }
};
