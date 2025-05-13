class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int ans=0;
        int y_x=0,x_y=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x'&&s2[i]=='y'){
                if(x_y==1){
                    ans++;
                    x_y=0;
                }
                else x_y++;
            }
            if(s1[i]=='y'&&s2[i]=='x'){
                if(y_x==1){
                    ans++;
                    y_x=0;
                }
                else y_x++;
            }
        }
        if(y_x>x_y||x_y>y_x) return -1;
        if(y_x==1) ans+=2;
        return ans;
    }
};
