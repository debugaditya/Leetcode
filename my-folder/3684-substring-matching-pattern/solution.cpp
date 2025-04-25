class Solution {
public:
    int find_start(string a,string s){
        if(a.size()==0) return -1;
        string temp=s.substr(0,a.size());
        for(int i=a.size()-1;i<s.size();i++){
            if(temp==a) return i;
            if(i+1<s.size()) temp+=s[i+1];
            temp.erase(temp.begin());
        }
        return s.size();
    }
    int find_back(string a,string s){
        if(a.size()==0) return s.size();
        string temp=s.substr(s.size()-a.size(),a.size());
        for(int i=s.size()-a.size();i>=0;i--){
            if(temp==a) return i;
            if(i-1>=0) temp.insert(temp.begin(),s[i-1]);
            temp.pop_back();
        }
        return -1;
    }
    bool hasMatch(string s, string p) {
        string a="";
        string b="";
        bool d=true;
        for(auto it:p){
            if(it=='*'){
                d=false;
                continue;
            }
            if(d) a+=it;
            else b+=it;
        }
        return find_start(a,s)<find_back(b,s);
    }
};
