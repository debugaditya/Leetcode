class Robot {
private:
       int w,h,x=0,y=0,dir=0;
       vector<vector<int>>mp={{1,0},{0,1},{-1,0},{0,-1}};
public:
    Robot(int width, int height) {
        w=width;
        h=height;
    }
    
    void step(int st) {
        int num=st%(2*(w+h-2));
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; // South
            return;
        }
        while(num>0){
            int prev_x=x,prev_y=y;
            x=min(w-1,max(x+mp[dir][0]*num,0));
            y=min(h-1,max(y+mp[dir][1]*num,0));
            num-=max(abs(x-prev_x),abs(y-prev_y));
            if(num>0) dir=(dir+1)%4;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir==0) return "East";
        if(dir==1) return "North";
        if(dir==2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(w, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
