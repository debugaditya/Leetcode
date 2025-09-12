class Solution {
public:
    bool check(string s, int size){
        string a= s.substr(0,size); vector<int>freq(26,0);
        for(auto it:a) freq[it-'a']++;
        for(int i=size;i<s.size();i+=size){
            vector<int>fr(26,0);
            for(int j=i;j<i+size;j++){
                fr[s[j]-'a']++;
                if(fr[s[j]-'a']>freq[s[j]-'a']) return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();
        vector<int>fact; for(int i=1;i<=n/2;i++) if(n%i==0) fact.push_back(i);
        for(auto it:fact) if(check(s,it)) return it;
        return n;
    }
};
