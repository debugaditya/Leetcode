class Solution {
public:
    bool is_int(string it){
        for(auto c:it) if(!isdigit(c)) return false;
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int maxi=0;
        for(auto it:strs){
            if(is_int(it)) maxi=max(maxi,stoi(it));
            else maxi=max(maxi,(int) it.size()); 
        }
        return maxi;
    }
};
