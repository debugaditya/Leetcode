class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int i1=a.size()-1;
        int i2=b.size()-1;
        string ans="";
        while(i1>=0&&i2>=0){
            if((a[i1]-'0')+(b[i2]-'0')+carry==0) ans.insert(ans.begin(),'0');
            else if((a[i1]-'0')+(b[i2]-'0')+carry==1){
                ans.insert(ans.begin(),'1');
                carry=0;
            }
            else if((a[i1]-'0')+(b[i2]-'0')+carry==2){
                ans.insert(ans.begin(),'0');
                carry=1;
            }
            else if((a[i1]-'0')+(b[i2]-'0')+carry==3) ans.insert(ans.begin(),'1');     
            i1--;
            i2--;       
        }
        while(i1>=0||i2>=0){
            if(i1>=0){
                if((a[i1]-'0')+carry==0) ans.insert(ans.begin(),'0');  
                else if((a[i1]-'0')+carry==1){
                    ans.insert(ans.begin(),'1');
                    carry=0;
                } 
                else if((a[i1]-'0')+carry==2) ans.insert(ans.begin(),'0');
            }
            if(i2>=0){
                if((b[i2]-'0')+carry==0) ans.insert(ans.begin(),'0');  
                else if((b[i2]-'0')+carry==1){
                    ans.insert(ans.begin(),'1');
                    carry=0;
                } 
                else if((b[i2]-'0')+carry==2) ans.insert(ans.begin(),'0');
            }
            i1--;
            i2--;
        }
        if(carry==1) ans.insert(ans.begin(),'1');
        return ans;
    }
};
