class Robot {
public:
    int idx=0;
    vector<vector<int>>pos;
    bool started=false;
    Robot(int width, int height) {
        
        //bottom row (l->r) East(0)
        for(int i=0;i<width;i++) pos.push_back({i,0,0});
        //right column (b->t) North(1)
        for(int i=1;i<height;i++) pos.push_back({width-1,i,1});
        //top row (r->l) West(2)
        for(int i=width-2;i>=0;i--) pos.push_back({i,height-1,2});
        //left column(t->d) South(3)
        for(int i=height-2;i>0;i--) pos.push_back({0,i,3});

        //make starting as South after complete full round
        //or it moved bcz without moving it cant come back to (0,0)
        pos[0][2]=3;
    }
    
    void step(int num) {
        started=true;
        idx= (idx+num) % pos.size();
    }   
    
    vector<int> getPos() {
        return {pos[idx][0],pos[idx][1]};
    }
    string getDir() {
        if(!started) return "East";
        int d=pos[idx][2];
        if(d==0) return "East";
        else if(d==1) return "North";
        else if(d==2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */