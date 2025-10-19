class Solution {
public:
    int binary_to_int(string &s){
        int ans=0,power=s.size()-1;
        for(auto &it:s){
            if(it!='0') ans+=pow(2,power);
            power--;
        }
        return ans;
    }
    bool hasAllCodes(string s, int k) {
        string window=s.substr(0,k); unordered_set<int>st;
        for(int i=k-1;i<s.size();i++){
            st.insert(binary_to_int(window));
            if(i+1<s.size()){
                window+=s[i+1];
                window.erase(window.begin());
            }
        }
        return st.size()==pow(2,k);
    }
};
