class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st; int ans=0;
        for(auto it:directions){
            if(st.empty()) st.push(it);
            else if(it=='L'&&st.top()=='S'){
                ans++; st.push('S');
            }
            else if(it=='L'&&st.top()=='R'){
                while(!st.empty()&&st.top()=='R'){ans++; st.pop();}
                ans++; st.push('S');
            }
            else if(it=='S'){
                while(!st.empty()&&st.top()=='R'){ans++; st.pop();}
                st.push('S');
            }
            else st.push(it);
        }
        return ans;
    }
};
