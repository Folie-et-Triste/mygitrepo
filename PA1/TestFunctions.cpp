#include "header.h"


void testWrapper::readfileDebug(){
    std::ifstream commandList("test.csv");
    std::cout << "Got this far";
    std::string temp;
    std::getline(commandList, temp);
    if (commandList.is_open()) {
        std::cout << temp;
    }
    else {
        std::cout << "Gone Wrong";
    }
    LinkedList<std::string> mainList;
    mainList.fillList( commandList);

    mainList.printList();
}