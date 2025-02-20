class Solution {
public:
    int dec(string s){
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            ans+=((s[i]-'0')*pow(2,s.size()-i-1));
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<int>st;
        for(auto it:nums) st.insert(dec(it));
        int w=0;
        while(st.find(w)!=st.end()) w++;
        string ans="";
        for(int j=1;j<=nums.size();j++){
            ans.insert(ans.begin(),w%2+'0');
            w/=2;
        }
        return ans;
    }
};
