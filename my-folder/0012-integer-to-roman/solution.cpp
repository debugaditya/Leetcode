class Solution {
public:
    string intToRoman(int num) {
        vector<string> mp0 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> mp1 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> mp2 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> mp3 = {"", "M", "MM", "MMM"};
        string ans="";
        int i=0;
        while(num>0){
            if(i==0) ans.insert(0,mp0[num%10]);
            if(i==1) ans.insert(0,mp1[num%10]);
            if(i==2) ans.insert(0,mp2[num%10]);
            if(i==3) ans.insert(0,mp3[num%10]);
            i++;
            num/=10;
        }
        return ans;
    }
};
