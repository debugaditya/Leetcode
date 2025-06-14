class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num); char j='a';
        string mini=s; for(auto &it:mini) if(it==s[0]) it='0';
        string maxi=s; 
        for(auto &it:maxi){
            if(it=='9') continue;
            if(j=='a') j=it;
            if(it==j) it='9';
        }
        return stoi(maxi)-stoi(mini);
    }
};
