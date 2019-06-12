//
// Created by henok on 6/12/19.
//

#ifndef ADDTASK_INPUTDATA_H
#define ADDTASK_INPUTDATA_H

//Input Data to be processed
class InputData {
private:
    int x;
    int y;
public:
    InputData(int x,int y): x(x),y(y){}
    int getX(){return x;}
    int getY(){return y;}
};


#endif //ADDTASK_INPUTDATA_H
