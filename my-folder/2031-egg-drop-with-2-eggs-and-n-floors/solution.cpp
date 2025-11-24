class Solution {
public:
    int twoEggDrop(int n) {
        int i=1;
        while(n>i){
            n-=i;
            i++;
        }
        return i;
    }
};
