class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        set<char>st;
        for(int i=0;i<allowed.size();i++){
            st.insert(allowed[i]);
        }
        for(int j=0;j<words.size();j++){
            bool d=true;
            for(int k=0;k<words[j].size();k++){
                if(st.find(words[j][k])==st.end()){
                    d=false;
                    break;
                }

            }
            if(d){
                ans++;
            }
        }
        return ans;
        
    }
};
