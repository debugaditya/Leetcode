class Solution {
public:
    bool sumGame(string num) {
        int q=0,sum=0;
        for(int i=0;i<num.size()/2;i++){
            if(num[i]=='?') q++; 
            else sum+=num[i]-'0';
            if(num[i+num.size()/2]=='?') q--;
            else sum-=num[i+num.size()/2]-'0';  
        }
        cout<<sum<<" "<<q;
        if(q%2) return true;
        if(q==0&&sum==0) return false;
        if(q*sum>=0) return true;
        if(9*abs(q)/2!=abs(sum)) return true;
        return false;
    }
};
