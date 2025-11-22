class Solution {
public:
    string sto(int i){
        string s="";
        while(i>0){
            s+=i%10+'0';
            i/=10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=max(num1,101);i<=num2;i++){
            string s=sto(i);
            for(int i=1;i<s.size()-1;i++){
                if(s[i]>s[i-1]&&s[i]>s[i+1]) {ans++; cout<<s<<endl;}
                if(s[i]<s[i-1]&&s[i]<s[i+1]) {ans++; cout<<s<<endl;}
            }
        }
        return ans;
    }
};
