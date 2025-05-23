class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e||b==f){
            if(a==e&&a!=c) return 1;
            if(b==f&&d!=f) return 1;
            if(a==e&&(d>min(b,f)&&d<max(b,f))) return 2;
            if(b==f&&(c>min(a,e)&&c<max(a,e))) return 2;
            return 1;
        }
        else if(abs(c-e)==abs(d-f)){
            if(abs(a-e)!=abs(b-f)||abs(a-c)!=abs(b-d)) return 1;
            if(a>max(c,e)||a<min(c,e)) return 1;
            return 2; 
        }
        return 2;
    }
};
