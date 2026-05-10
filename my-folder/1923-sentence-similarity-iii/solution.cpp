class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        string word=""; 
        vector<string>v1,v2; int i=0;
        for(auto it:s1){
            if(it==' ') {
                v1.push_back(word);
                word="";
            }
            else word+=it;
        }
        v1.push_back(word); word="";
        for(auto it:s2){
            if(it==' ') {
                v2.push_back(word);
                word="";
            }
            else word+=it;
        }
        v2.push_back(word);
        int mini=min((int)v1.size(),(int)v2.size());
        while(v1[i]==v2[i]){i++; mini--; if(mini==0) return true;} i=1;
        while(v1[v1.size()-i]==v2[v2.size()-i]){i++; mini--; if(mini==0) return true;}
        return false;
    }
};
