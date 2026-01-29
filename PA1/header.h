#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
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
template <typename T> class LinkedList{
    private:
    Node<T>* head;
    public:
    LinkedList();
    void setHead(Node<T>* newHead);
    Node<T>* getHead();
    bool isEmpty();
    
    void deleteNode(T command);
    void printList();
    
    void fillList(std::ifstream& commandList);
    void addtoEnd(T x1, T x2, T x3);
}; 


class gameboardWrapper{
private:
int questions = 20;
int playerScore = 0;
int leaderBoard[10]= {0};
public:
void printRules();

    
};

class testWrapper{
    public:
    void readfileDebug();
    
};


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
    std::cout<< command << desc << score;
}


//LinkedList Functions

template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;

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
void LinkedList<T>::fillList(std::ifstream& commandList){
    
    T temp = "";
    T temp2= "";
    T temp3 = "";
    std::getline(commandList,temp,',');
std::cout << temp;
    std::getline(commandList, temp2 ,',');
    std::getline(commandList,temp3);


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

#endif