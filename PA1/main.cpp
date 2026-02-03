#include "header.h"
// Unclear if the question refers to using a linked list for the command list or the leaderboard but I guess its the same either way
//An advantage for using a linked list for the command list is the ease of editing the list, such as with the delete command in the program
// A dissadvantage would be the navagation of the list, with an array you could just randomly generate a number and plug that in but with a list
// you have to traverse the list and deal with pointers, just kinda a pain. 
// for the leaderboard I chose to use an array due to being able to more easily put a hard cap on the entries. Don't have to worry about having people
// being added ad infinitum or counting the entries everytime to maintain a limit 

int main(){
    std::fstream commandList("commands.csv");
LinkedList<std::string>* gameList = new LinkedList<std::string>;
    gameList->fillList(commandList);
    gameboardWrapper gameBoard;
    gameBoard.setList(gameList);
    gameBoard.loadleaderBoard();
    while(true){
    gameBoard.mainMenu();
}
}