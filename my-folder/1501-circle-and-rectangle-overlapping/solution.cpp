class Solution {
public:
    pair<int,int> get_x(int y,int c1,int c2,int r){
        int diff=r*r-(y-c2)*(y-c2);
        if(diff<0) return {INT_MAX,INT_MIN};
        int d=1.0*sqrt(diff);
        return {d+c1,c1-d};
    }
    pair<int,int> get_y(int x,int c1,int c2,int r){
        int diff=r*r-(x-c1)*(x-c1);
        if(diff<0) return {INT_MAX,INT_MAX};
        int d=1.0*sqrt(diff);
        return {d+c2,c2-d};
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter>=x1&&xCenter<=x2&&yCenter>=y1&&yCenter<=y2) return true;
        if((xCenter-x1)*(xCenter-x1)+(yCenter-y1)*(yCenter-y1)<=radius*radius) return true;
        pair<int,int>p1=get_x(y1,xCenter,yCenter,radius);
        if(p1.first>=x1&&p1.first<=x2) return true;
        if(p1.second>=x1&&p1.second<=x2) return true;
        pair<int,int>p2=get_x(y2,xCenter,yCenter,radius);
        if(p2.first>=x1&&p2.first<=x2) return true;
        if(p2.second>=x1&&p2.second<=x2) return true;
        pair<int,int>p3=get_y(x1,xCenter,yCenter,radius);
        if(p3.first>=y1&&p3.first<=y2) return true;
        if(p3.second>=y1&&p3.second<=y2) return true;
        pair<int,int>p4=get_y(x2,xCenter,yCenter,radius);
        if(p4.first>=y1&&p4.first<=y2) return true;
        if(p4.second>=y1&&p4.second<=y2) return true;
        return false;
    }
};
