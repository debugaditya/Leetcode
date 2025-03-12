class Solution {
public:
    int ladderLength(string b, string e, vector<string>& words) {
        unordered_set<string>st(words.begin(),words.end());
        queue<pair<string,int>>q;
        q.push({b,1});
        st.erase(b);
        if(st.find(e) == st.end()) return 0;
        while(!q.empty()){
            string s=q.front().first;
            int l=q.front().second;
            q.pop();
            if(s==e) return l;
            for(int i=0;i<s.size();i++){
                for(char j='a';j<='z';j++){
                    string temp=s;
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        q.push({temp,l+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
