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
    string addStrings(string num1, string num2) {
        add(num1,num2);
        return num1;
    }
};
