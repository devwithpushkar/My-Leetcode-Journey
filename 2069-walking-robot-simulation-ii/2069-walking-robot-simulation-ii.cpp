class Robot {
public:
    int width;
    int height;
    int pos;
    int perimeter;
    bool moved = false;

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        pos = 0;
        perimeter = 2 * (width-1) + 2 * (height-1);
    }
    
    void step(int num) {
        pos = (pos + num) % perimeter;
        if(moved == false) moved = true;
    }
    
    vector<int> getPos() {
        int x;
        int y;
        if(pos < width) {
            x = pos;
            y = 0;
        } else if(pos < width + height - 1) {
            x = width-1;
            y = pos - (width-1);
        } else if(pos < 2*width + height - 2) {
            x = (width - 1) - (pos - (width + height - 2));
            y = height - 1;
        } else {
            x = 0;
            y = (height - 2) - (pos - (2*width + height - 2));
        }
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        return temp;
    }
    
    string getDir() {
        if(!moved && pos == 0) return "East";
        if(pos == 0) return "South";
        
        if(pos < width) {
            return "East";
        } else if (pos < width + height - 1) {
            return "North";
        } else if (pos < 2*width + height - 2) {
            return "West";
        } else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */