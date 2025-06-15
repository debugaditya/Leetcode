class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num); char j='a'; char k='a';
        string mini=s; string maxi=s; 
        for(auto &it:mini){
            if(it=='1'||it=='0') continue;
            if(k=='a') k=it;
            if(k==s[0]&&it==k) it='1';
            else if(it==k) it='0';
        }
        for(auto &it:maxi){
            if(it=='9') continue;
            if(j=='a') j=it;
            if(it==j) it='9';
        }
        cout<<mini<<" "<<maxi;
        return stoi(maxi)-stoi(mini);
    }
};
