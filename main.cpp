#include <iostream>
#include"hedgehog.h"
#include "./task/AddTask.h"
#include "./data/InputData.h"
int main() {
    //Initialize Add Task
    std::shared_ptr<AddTask> addTask = std::make_shared<AddTask>("AddTask",4);

    //Start Graph
    auto myGraph = std::make_shared<Graph<int, InputData>>();

    //Source
    myGraph->input(addTask);

    //Sink
    myGraph->output(addTask);

    //Run graph
    myGraph->executeGraph();

    //Consume data
    for(int i=0;i<10;i++){
        myGraph->pushData(std::make_shared<InputData>(i,i));
    }
    myGraph->finishPushingData();

    //Produce Data
    while(std::shared_ptr<int> graphOutput = myGraph->getBlockingResult()){
        std::cout<<*graphOutput<<std::endl;
    }

    myGraph->waitForTermination();

    //Generate dot file
    myGraph->createDotFile("AddTask.dot",ColorScheme::WAIT,StructureOptions::ALL);
    return 0;
}