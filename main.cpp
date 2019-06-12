#include <iostream>
#include"hedgehog.h"
#include "./task/AddTask.h"
#include "./data/InputData.h"
int main() {
    std::shared_ptr<AddTask> addTask = std::make_shared<AddTask>();

    auto myGraph = std::make_shared<Graph<int, InputData>>();
    myGraph->input(addTask);
    myGraph->output(addTask);
    myGraph->executeGraph();

    for(int i=0;i<10;i++){
        std::shared_ptr<InputData> inputData = std::make_shared<InputData>(i,i);

        myGraph->pushData(inputData);
    }
    myGraph->finishPushingData();

    while(std::shared_ptr<int> graphOutput = myGraph->getBlockingResult()){
        std::cout<<*graphOutput<<std::endl;
    }

    myGraph->waitForTermination();
    myGraph->createDotFile("AddTask.dot");
    return 0;
}