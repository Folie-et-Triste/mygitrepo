#include "header.h"


void TestisEmpty(){
    LinkedList<std::string> Test;
    assert(Test.isEmpty() == true);
    std::string Tstring = "text1", Tstring2 = "text2", Tstring3 = "text3";
    Test.addtoEnd(Tstring, Tstring2, Tstring3);
    assert(Test.isEmpty() == false);
    std::cout << "Passed";
}

void TestaddtoEnd(){
     LinkedList<std::string> Test;
    assert(Test.isEmpty() == true);
    std::string Tstring = "text1", Tstring2 = "text2", Tstring3 = "text3";
    Test.addtoEnd(Tstring, Tstring2, Tstring3);
    assert(Test.getHead()->getCommand() == "text1" );
    assert(Test.getHead()->getDesc() == "text2");
    assert(Test.getHead()->getScore() == "text3");
    std::cout << "Passed";

}
void Testdelete(){
    LinkedList<std::string> Test;
    
    assert(Test.isEmpty() == true);
    std::string Tstring = "text1", Tstring2 = "text2", Tstring3 = "text3";
    Test.addtoEnd(Tstring, Tstring2, Tstring3);
    Test.deleteNode("text1");
    assert(Test.isEmpty()== true);
    Test.addtoEnd(Tstring, Tstring2, Tstring3);
    Test.addtoEnd("Lorum", "Ipsum", "dolor");
    Test.deleteNode("text1");
    assert(Test.getHead()->getCommand() == "Lorum");
    std::cout << "Passed";



}
void TestFile(){
LinkedList<std::string> Test;
std::fstream testFile("test.csv");
Test.fillList(testFile);
assert(Test.getHead()->getCommand() == "test1");
std::cout << "Passed";
std::fstream testFile("emptytest.csv");
LinkedList<std::string> Test2;
Test2.fillList(testFile);
assert(Test2.isEmpty() == true);

}


