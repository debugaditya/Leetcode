class Solution {
public:
    void add(string &ans,string &temp){
        int carry=0,i=ans.size()-1,j=temp.size()-1;
        while(i>=0&&j>=0){
            int cr=(carry+ans[i]-'0'+temp[j]-'0')/10;
            ans[i]=(carry+ans[i]-'0'+temp[j]-'0')%10+'0';
            carry=cr; i--; j--;
        }
        while(j>=0){
            int cr=(carry+temp[j]-'0')/10;
            ans.insert(ans.begin(),(carry+temp[j]-'0')%10+'0');
            carry=cr; j--;
        }
        while(i>=0&&carry>0){
            int cr=(carry+ans[i]-'0')/10;
            ans[i]=(carry+ans[i]-'0')%10+'0';
            carry=cr; i--;
        }
        if(carry>0) ans.insert(ans.begin(),carry+'0');
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int zeroes=0; string ans="";
        for(int i=num2.size()-1;i>=0;i--){
            int carry=0; string temp="";
            for(int j=num1.size()-1;j>=0;j--){
                temp+=(carry+(num2[i]-'0')*(num1[j]-'0'))%10+'0';
                carry=(carry+(num2[i]-'0')*(num1[j]-'0'))/10;
            }
            if(carry>0) temp+=carry+'0';
            reverse(temp.begin(),temp.end());
            for(int j=1;j<=zeroes;j++) temp+='0'; zeroes++;
            add(ans,temp);
        }
        return ans;
    }
};
