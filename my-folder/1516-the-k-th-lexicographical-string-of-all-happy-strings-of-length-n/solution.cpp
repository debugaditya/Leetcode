class Solution {
public:
    void f(int n,priority_queue<string>&pq,string s){
        if(s.size()==n){
            pq.push(s);
            return;
        }
        string temp1=s;
        string temp2=s;
        string temp3=s;
        if(temp1.empty()||s.back()!='a') temp1+='a';
        if(temp2.empty()||s.back()!='b') temp2+='b';
        if(temp3.empty()||s.back()!='c') temp3+='c';
        if(temp1.size()>s.size()) f(n,pq,temp1);
        if(temp2.size()>s.size()) f(n,pq,temp2);
        if(temp3.size()>s.size()) f(n,pq,temp3);
        return;
    }
    string getHappyString(int n, int k) {
        string s="";
        priority_queue<string>pq;
        f(n,pq,s);
        if(pq.size()<k) return s;
        int rank=pq.size()-k;
        while(rank--) pq.pop();
        return pq.top();
    }
};
