//
// Created by henok on 6/12/19.
//

#ifndef ADDTASK_ADDTASK_H
#define ADDTASK_ADDTASK_H

#include<iostream>
#include "hedgehog.h"
#include "../data/InputData.h"

class AddTask: public AbstractTask<int, InputData> {
public:
    //AddTask(const std::string_view &name,size_t numberThreads) : AbstractTask(name, numberThreads){}
    AddTask(){}

    void execute(std::shared_ptr<InputData> inputData) override{
        std::shared_ptr<int> x = std::make_shared<int>(inputData->getX());
        std::shared_ptr<int> y = std::make_shared<int>(inputData->getY());

        //Add the values for the given inputData
        std::shared_ptr<int> total = std::make_shared<int>((*x)+(*y));

        //Add to producer
        addResult(total);
    }

};

#endif //ADDTASK_ADDTASK_H
