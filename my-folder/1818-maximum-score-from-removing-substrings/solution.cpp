class Solution {
public:
    int maximumGain(string str, int x, int y) {
        int ans=0,mini=min(x,y),maxi=max(x,y);
        char s,l; if(x>=y){s='a'; l='b';} else {s='b'; l='a';} stack<char>st;
        for(auto &it:str){
            if(it==s) st.push(it);
            else if(it==l){
                if(st.empty()||st.top()==it) st.push(it);
                else{ans+=maxi; st.pop();}
            }
            else{
                string temp=""; 
                while(!st.empty()){temp+=st.top(); st.pop();}
                reverse(temp.begin(),temp.end());
                for(auto &it1:temp){
                    if(it1==l) st.push(it1);
                    else if(it1==s){
                        if(st.empty()||st.top()==it1) st.push(it1);
                        else{ans+=mini; st.pop();}
                    }
                }
                while(!st.empty()) st.pop();
            }
        }
        string temp=""; 
        while(!st.empty()){temp+=st.top(); st.pop();}
        reverse(temp.begin(),temp.end());
        for(auto &it1:temp){
             if(it1==l) st.push(it1);
            else if(it1==s){
                if(st.empty()||st.top()==it1) st.push(it1);
                else{ans+=mini; st.pop();}
            }
        }
        return ans;
    }
};
