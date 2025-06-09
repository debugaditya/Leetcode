class Solution {
public:
    string alphabetBoardPath(string t) {
        string ans=""; char prev='a';
        for(auto it:t){
            if(it=='z'){
                if((prev-'a')%5<(it-'a')%5) for(int i=1;i<=(it-'a')%5-(prev-'a')%5;i++) ans+='R';
                else for(int i=1;i<=(prev-'a')%5-(it-'a')%5;i++) ans+='L';
                if((prev-'a')/5<(it-'a')/5) for(int i=1;i<=(it-'a')/5-(prev-'a')/5;i++) ans+='D';
                else for(int i=1;i<=(prev-'a')/5-(it-'a')/5;i++) ans+='U';
                prev=it; ans+='!'; continue;
            }
            if((prev-'a')/5<(it-'a')/5) for(int i=1;i<=(it-'a')/5-(prev-'a')/5;i++) ans+='D';
            else for(int i=1;i<=(prev-'a')/5-(it-'a')/5;i++) ans+='U';
            if((prev-'a')%5<(it-'a')%5) for(int i=1;i<=(it-'a')%5-(prev-'a')%5;i++) ans+='R';
            else for(int i=1;i<=(prev-'a')%5-(it-'a')%5;i++) ans+='L';
            prev=it;
            ans+='!';
        }
        return ans;
    }
};
