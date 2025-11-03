class Solution {
public:
    string strWithout3a3b(int a, int b) {
        char maxi,mini; string s="";
        if(a>b) {maxi='a'; mini='b';}
        else {maxi='b'; mini='a';}
        while(a>0&&b>0){
            if(abs(a-b)<=2){
                s+=maxi; s+=mini;
                a--; b--;
            }
            else{
                s+=maxi; s+=maxi;  s+=mini;
                if(maxi=='a') {a-=2; b--;}
                else {a--; b-=2;}
            }
        }
        while(a>0) {s+='a'; a--;} while(b>0) {s+='b'; b--;}
        return s;
    }
};
