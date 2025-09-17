class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();i++){
            if(i==bits.size()-1) return bits[i]==0;
            if(bits[i]==1) i++;
        }
        return false;
    }
};
