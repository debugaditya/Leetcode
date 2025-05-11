class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>st;
        for(auto it:t){
            if(it=="+"){
                int sum=st.top(); st.pop();
                sum+=st.top(); st.pop();
                st.push(sum);
            }
            else if(it=="-"){
                int sum=-st.top(); st.pop();
                sum+=st.top(); st.pop();
                st.push(sum);
            }
            else if(it=="*"){
                int sum=st.top(); st.pop();
                sum*=st.top(); st.pop();
                st.push(sum);
            }
            else if(it=="/"){
                int s1=st.top(); st.pop();
                int s2=st.top(); st.pop();
                st.push(s2/s1);
            }
            else st.push(stoi(it));
        }
        return st.top();
    }
};
