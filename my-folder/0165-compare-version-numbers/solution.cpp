class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0; string r1="",r2="";
        while(i<v1.size()&&j<v2.size()){
            while(i<v1.size()&&v1[i]!='.') r1+=v1[i++];
            while(j<v2.size()&&v2[j]!='.') r2+=v2[j++];
            cout<<r1<<" "<<r2<<endl;
            if(stoi(r1)>stoi(r2)) return 1;
            if(stoi(r1)<stoi(r2)) return -1;
            r1=""; r2="";
            i++; j++;
        }
        while(i<v1.size()) {if(v1[i]!='0'&&v1[i]!='.') return 1; i++;}
        while(j<v2.size()) {if(v2[j]!='0'&&v2[j]!='.') return -1; j++;}
        return 0;
    }
};
