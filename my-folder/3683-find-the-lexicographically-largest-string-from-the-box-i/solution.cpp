class Solution {
public:
    string answerString(string word, int numFriends) {
        int size=word.size()-numFriends+1;
        if(numFriends==1) return word;
        string maxi="";
        for(int i=0;i<numFriends;i++){
            maxi=max(maxi,word.substr(i,size));
        }
        for(int j=numFriends;j<word.size();j++){
            maxi=max(maxi,word.substr(j,word.size()-j));
        }
        return maxi;
    }
};
