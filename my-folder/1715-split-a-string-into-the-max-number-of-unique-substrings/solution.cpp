class Solution {
public:
    int ans=1; unordered_set<string>st; 
    void f(string &s,string &a,int i,int k){
        a+=s[i];
        if(i==s.size()-1){
            if(!st.count(a)) ans=max(ans,k+1);
            a.pop_back();
            return;
        }
        f(s,a,i+1,k);
        if(!st.count(a)){
            st.insert(a);
            string temp=a; a="";
            f(s,a,i+1,k+1);
            a=temp;
            st.erase(a);
        }
        a.pop_back();
    }
    int maxUniqueSplit(string s) {
        string a="";
        f(s,a,0,0);
        return ans;
    }
};
