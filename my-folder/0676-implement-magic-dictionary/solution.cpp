class MagicDictionary {
public:
    vector<string>v;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        v=dictionary;
    }
    
    bool search(string w) {
        for(auto it:v){
            if(it.size()!=w.size()) continue; int cnt=0;
            for(int i=0;i<w.size();i++) if(w[i]!=it[i]) cnt++;
            if(cnt==1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
