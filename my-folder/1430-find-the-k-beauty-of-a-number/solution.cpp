class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int z=num,cnt=0; string s=to_string(num);
        string temp=s.substr(0,k);
        for(int i=0;i<s.size()-k+1;i++){
            int a=stoi(temp);
            if(a!=0&&z%a==0) cnt++;
            temp.erase(temp.begin());
            if(i+k<s.size()) temp+=s[i+k];
        }
        return cnt;
    }
};
