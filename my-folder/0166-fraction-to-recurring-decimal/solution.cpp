class Solution {
public:
    string fractionToDecimal(int nume, int deno) {
        if(nume==0) return "0";
        string ans=""; unordered_map<int,int>mp; bool d=false;
        long long num=nume,den=deno;
        if((num<0&&den>0)||(num>0&&den<0)) ans+='-';
        num=abs(num); den=abs(den);
        while(num>0){
            if(d&&mp.count(num)){
                ans+=')';
                ans.insert(ans.begin()+mp[num],'('); 
                return ans;
            }
            if(d) mp[num]=ans.size();
            ans+=to_string(num/den);
            num%=den;
            if(!d&&num>0) {ans+='.'; d=true;}
            if(d) num*=10;
        }
        return ans;
    }
};
