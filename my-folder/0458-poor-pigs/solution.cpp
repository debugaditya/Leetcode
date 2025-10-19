class Solution {
public:
    int poorPigs(int &b, int &md, int &mt) {
        int l=0,r=b;
        while(l<=r){
            if(pow(mt/md+1,(l+r)/2)>=b) r=(l+r)/2-1;
            else l=(l+r)/2+1;
        }
        return l;
    }
};
