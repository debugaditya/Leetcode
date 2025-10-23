class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1==word2) return true;
        vector<int>mp1(26,0),mp2(26,0); 
        for(auto &it:word1) mp1[it-'a']++; for(auto &it:word2) mp2[it-'a']++; 
        for(int i=0;i<26;i++){
            if((mp2[i]==0&&mp1[i]>0)||(mp1[i]==0&&mp2[i]>0)) return false;
            if(mp1[i]==0||mp1[i]==mp2[i]) continue; bool d=false;
            for(int j=i+1;j<26;j++){
                if(mp2[j]==0) continue;
                if(mp1[j]==mp2[i]){
                    d=true;
                    swap(mp1[i],mp1[j]);
                }
            }
            if(!d) return false;
        }
        return true;
    }
};
