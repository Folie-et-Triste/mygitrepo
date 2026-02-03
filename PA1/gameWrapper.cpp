#include "header.h"
//gameboard Wrapper Functions
gameboardWrapper::gameboardWrapper(){
int playerScore = 0;
LinkedList<std::string>* mainList;
std::string Leaderboard[2][10] = {""};
Node<std::string>* question;

}
LinkedList<std::string>* gameboardWrapper::getList(){
    return this->mainList;
}
void gameboardWrapper::setList(LinkedList<std::string>* newList){
mainList = newList;
}
void gameboardWrapper::addCommand(){
    std::string newCommand ="";
    std::string newDesc = "";
    std::string newScore =" ";
    std::cout << "Enter Command";
    std::cin >> newCommand;
    std::cout << "Enter Description";
    std::cin>>  newDesc;
    std::cout<< "Enter Score";
    std::cin >> newScore; 
    mainList->addtoEnd(newCommand,newDesc,newScore);
    

}

void gameboardWrapper::deleteCommand(){        
    if(mainList->isEmpty()){
        std::cout << "Add something first";

        return;
    }else{
    std::string temp = "";
    std::cout << "Enter Command to be Deleted";
    std::cin >> temp;

    Node<std::string>* current = mainList->getHead();
    
    Node<std::string>* prev = mainList->getHead();
    
    while(temp != current->getCommand()){
    prev = current;
    current = current->getnextPtr();
    }
    prev->setnextPtr(current->getnextPtr());
    current->setnextPtr(nullptr);
    delete current;
    return;

}
}
void gameboardWrapper::printRules(){
    std::cout <<"The user will be presented with 20 MCQs on linux commands and their scores will be tracked for maintaining leaderboard.";
}
void gameboardWrapper::mainMenu(){  // main interface of game
    int playerSelect = 0;
    while(true){
        std::cout << "enter selection: \n 1.Play Game \n 2.See Rules \n 3. Add Command \n 4. Delete Command \n 5. Show all Commands \n 6. See LeaderBoard  \n 7. Save and Exit";
        std::cin >> playerSelect; 
        std::cout << "Step one \n";
        switch(playerSelect){
            case 1:
            std::cout << "Step two\n";
            playGame();
            break;
            case 2:
            printRules();
            break;
            case 3: 
            addCommand();
            break;
            case 4:
            deleteCommand();
            break;
            case 5:
            mainList->printList();
            break;
            case 6:
            printRules();
            break;
            case 7:
            saveandExit();
            break;


        }
    }
}
void gameboardWrapper::loadleaderBoard(){
    std::fstream fileBoard("Leaderboard.csv");
    std::string tempname;
    std::string tempscore;
    int counter= 0;
    
    while(!fileBoard.eof() && counter <=9){
    std::getline(fileBoard,tempname,',');
    std::getline(fileBoard,tempscore);
    this->Leaderboard[0][counter] = tempname;
    this->Leaderboard[1][counter]= tempscore;
    counter++;

    }


}
void gameboardWrapper::addtoleaderBoard(std::string name , std::string score){
std::string temp = Leaderboard[1][0];
int counter = 0;
std::string nameholder;
std::string scoreholder;

while(stoi(score)<= stoi(temp)){
    counter++;
    temp = Leaderboard[1][counter];
}

for( int i = counter; i<8;i++){
    std::string nameholder = Leaderboard[0][counter];
std::string scoreholder = Leaderboard[1][counter];
Leaderboard[0][counter] = name;
Leaderboard[1][counter]= score;
name = Leaderboard[0][counter+1];
score = Leaderboard[0][counter+1];
Leaderboard[0][counter+1] = name;
Leaderboard[1][counter+1]= score;}






}

bool gameboardWrapper::checkusedWords(std::string usedWords[],std::string word, int counter){
    for(int i = 0; i < counter; i++){
        if(word == usedWords[counter]){
            return true;
        }

    }
    return false;
}

void gameboardWrapper::playGame(){  // game logic
    std::cout << "step three \n";
    std::string usedWords[19];
    std::string input;
    
    for(int roundCount = 1; roundCount <20; roundCount++){
        std::cout<< "Step Pre-do";
        do {
            std::cout << "step four \n";
        int traverse = rand() % roundCount +1;
            question = mainList->traverseList(traverse);
    }while(checkusedWords(usedWords, question->getCommand(), roundCount));

        std::cout << "Enter which command does this:" << question->getDesc();
        std::cin >> input; 
        if(input == question->getCommand()){
            std::cout << "Correct!";
            playerScore = playerScore + stoi(question->getScore());
        }else{
            std::cout <<" Incorrect.";
        }
        usedWords[roundCount] = question->getCommand();
    std::cout << "Your score is" << playerScore;
    }
    std::cout << "Your final score is" << playerScore;
}

void gameboardWrapper::saveandExit(){
    std::ofstream commands("commands.csv");
    std::ofstream leader("Leaderboard.csv");
    Node<std::string>* current = mainList->getHead(); 
   std::cout<<  current->getCommand();
   std::cout <<current->getDesc();
    std::string temp;
    while(current->getnextPtr() != nullptr){
        temp = current->getCommand();
        temp.append(",");
        temp.append(current->getDesc()+",");
        
        temp.append(current->getScore());
        std::cout << temp;
        std::cout <<"Step Nine";
        commands << temp;
        commands << "\n";
        current = current->getnextPtr();

    }
      temp = current->getCommand();
        temp.append(",");
        temp.append(current->getDesc()+",");
        
        temp.append(current->getScore());
        std::cout << temp;
        std::cout <<"Step Nine";
        commands << temp;
        commands << "\n";
        current = current->getnextPtr();


    commands.close();
    temp = current->getCommand() + current->getDesc() + current->getScore();
        commands << temp + "\n";
        
        for (int i = 0;i<=9; i++ ){
        temp =(Leaderboard[0][i]);
        temp.append(Leaderboard[1][i]);
            leader << temp;
        }
        delete mainList;
        exit(0);
    } 
   


