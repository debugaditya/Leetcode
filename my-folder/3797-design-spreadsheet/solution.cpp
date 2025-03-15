class Spreadsheet {
public:
    vector<vector<int>>v;
    Spreadsheet(int rows) : v(rows, vector<int>(26, 0)) {}
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        v[row][col]=value;
        return;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        v[row][col]=0;
        return;
    }
    
    int getValue(string f) {
        int ans=0;
        int p;
        for(int i=0;i<f.size();i++) if(f[i]=='+') p=i;
        string s1=f.substr(1,p-1);
        string s2=f.substr(p+1);
        if(isdigit(s1[0])) ans+=stoi(s1);
        else{
            int col=s1[0]-'A';
            int row=stoi(s1.substr(1))-1;
            ans+=v[row][col];
        }
        if(isdigit(s2[0])) ans+=stoi(s2);
        else{
            int col=s2[0]-'A';
            int row=stoi(s2.substr(1))-1;
            ans+=v[row][col];
        }
        return ans;
    }
};

