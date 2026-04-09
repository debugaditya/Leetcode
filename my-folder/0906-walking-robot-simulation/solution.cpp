class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>>st(obstacles.begin(),obstacles.end());
        vector<int>dir={0,1}; int x=0,y=0,ans=0; 
        for(auto it:commands){
            if(it<0){
                if(it==-1){
                    if(dir[0]==0&&dir[1]==1){dir[0]=1; dir[1]=0;}
                    else if(dir[0]==0&&dir[1]==-1){dir[0]=-1; dir[1]=0;}
                    else if(dir[0]==1&&dir[1]==0){dir[0]=0; dir[1]=-1;}
                    else if(dir[0]==-1&&dir[1]==0){dir[0]=0; dir[1]=1;}
                }
                else{
                    if(dir[0]==0&&dir[1]==1){dir[0]=-1; dir[1]=0;}
                    else if(dir[0]==0&&dir[1]==-1){dir[0]=1; dir[1]=0;}
                    else if(dir[0]==1&&dir[1]==0){dir[0]=0; dir[1]=1;}
                    else if(dir[0]==-1&&dir[1]==0){dir[0]=0; dir[1]=-1;}
                }
            }
            else{
                for(int i=1;i<=it;i++){
                    x+=dir[0]; y+=dir[1];
                    if(st.count({x,y})){
                        x-=dir[0]; y-=dir[1];
                        break;
                    }
                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;
    }
};
