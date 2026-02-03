#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

//Node Defination
template <typename T> class Node{
    private:
    T command;
    T desc;
    T score;
    Node* nextPtr = nullptr;
    
public:
Node(T x, T x2, T x3);
void setnextPtr(Node<T>* newNext);
void setcommand(T newCommand );
void setdesc(T newDesc); 
void setscore(T newScore);
void printAll();
Node<T>* getnextPtr();
T getCommand();
T getDesc();
T getScore();
};

//LinkedList Class Defination 
template <typename T> class LinkedList{
    private:
    Node<T>* head;
    public:
    LinkedList();
    ~LinkedList();
    void setHead(Node<T>* newHead);
    Node<T>* getHead();
    bool isEmpty();
    void deleteNode(T command);
    void printList();
    Node<T>* traverseList(int count);
    void fillList(std::fstream& commandList);
    void addtoEnd(T x1, T x2, T x3);
}; 

//gameboard Wrapper Declrations
class gameboardWrapper{
private:

int playerScore = 0;
LinkedList<std::string>* mainList;
std::string Leaderboard[2][10] = {""};
Node<std::string>* question;

public:
 gameboardWrapper();
 void setList(LinkedList<std::string>* newList);
 LinkedList<std::string>* getList();
int getroundCount();
int getplayerScore();
int getleaderBoard(int x=0, int y = 0);
Node<std::string> getQuestion();
void setroundCount(int newCount);
void setplayerScore(int newScore);
void setleaderBoard(std::string newEntry, int x, int y);
void setQuestion(Node<std::string>* newQuestion);
void mainMenu();
void addCommand();
void playGame();
void deleteCommand();
void printRules();
void printLeader();
void saveandExit(); // saves files and free memory before ending program
void addtoleaderBoard(std::string name , std::string score);
void loadleaderBoard();
bool checkusedWords(std::string usedWords[],std::string word, int counter); //checks an array of used words to see if current command has been asked already
};

class testWrapper{
    public:
    void readfileDebug();
    
};

//Function Defintions


//Node Functions
template <typename T>
Node<T>::Node(T x, T x2, T x3){
    command = x;
    desc = x2;
    score = x3;
    nextPtr = nullptr;

}
template <typename T>
void Node<T>::setcommand(T newcommand){
this->command = newcommand;
}
template <typename T>
void Node<T>::setdesc(T newDesc){
this->desc= newDesc;
}
template <typename T>
void Node<T>::setscore(T newScore){
    this->score = newScore;
}
template <typename T>
void Node<T>::setnextPtr(Node<T>* newNext){
this->nextPtr = newNext;
}
template <typename T>
T Node<T>::getCommand(){
return this->command;
}
template <typename T>
T Node<T>::getDesc(){
    return this->desc;
}
template <typename T>
T Node<T>::getScore(){
    return this->score;
}
template <typename T>
Node<T>* Node<T>::getnextPtr(){
return this->nextPtr;
}
template <typename T>
void Node<T>::printAll(){
    std::cout<< command << desc << score <<"\n";
}


//LinkedList Functions

template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;

}
template <typename T>
LinkedList<T>::~LinkedList(){
 delete head;
}

template <typename T>
void LinkedList<T>::setHead(Node<T>* newHead){
    this->head = newHead;

}

template <typename T>
bool LinkedList<T>::isEmpty(){
    if (this->head == nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename T>
Node<T> * LinkedList<T>::getHead(){
    return this-> head;


}

template <typename T>
void LinkedList<T>::addtoEnd(T x1, T x2, T x3){
     Node<T>* newNode = new Node<T>(x1,x2,x3);
     if (isEmpty()){
        this->head = newNode;    
     } else{
        Node<T>* temp = head;
        while(temp->getnextPtr() != nullptr){
            temp = temp->getnextPtr();}
        temp->setnextPtr(newNode);
        }
     }


template <typename T>
void LinkedList<T>::fillList(std::fstream& commandList){
    
    T temp = "";
    T temp2= "";
    T temp3 = "";


while (!commandList.eof()){
    
    std::getline(commandList,temp,',');
    std::getline(commandList, temp2 ,',');
    std::getline(commandList,temp3);
    this->addtoEnd(temp,temp2,temp3);

 }


}
template <typename T>
void LinkedList<T>::printList(){
    Node<T>* current;
    current = this->head;
while (current->getnextPtr()!= nullptr){
    current->printAll();
    
    current = current->getnextPtr();

}
 current->printAll();
 return;
}
template <typename T>
Node<T>* LinkedList<T>::traverseList(int count){
    if (!isEmpty()){
    Node<T>* current;
    
    current = this->head;
    std::cout << "step five \n";
    for(int i = count; i >0; i--){
        std::cout << "For Step";
        if(current->getnextPtr()!= nullptr){
        std::cout << "For Step Second";
        current = current->getnextPtr();
    }}
    std::cout << "step six \n";
    return current;
}else{
    std::cout << "List Empty";
    return nullptr;
}

}



#endif