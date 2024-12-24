class Solution {
public:
    bool isValid(string s) {
        vector<int>v;
        int a=0,b=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                a++;
                v.push_back(1);
            }
            if(s[i]==')'){
                a--;
                if(a<0||b<0||c<0) return false;
                if(v.back()!=1) return false;
                v.pop_back();
            }
            if(s[i]=='{'){
                b++;
                v.push_back(2);
            }
            if(s[i]=='}'){
                b--;
                if(a<0||b<0||c<0) return false;
                if(v.back()!=2) return false;
                v.pop_back();
            }
            if(s[i]=='['){
                c++;
                v.push_back(3);
            }
            if(s[i]==']'){
                c--;
                if(a<0||b<0||c<0) return false;
                if(v.back()!=3) return false;
                v.pop_back();
            }
            
        }
        if(a==0&&b==0&&c==0) return true;
        return false;
    }
};
