#include "chessProject.h"

#include <iostream>
#include <string>


using namespace std;

int main(){
    bool exit = false;
    int menuSelection;
    string playerOneName;
    string playerTwoName;
    
    while (exit != true){
        cout << "MAIN MENU" << endl;
        cout << "Please select an option (1 - ). Type 0 for exit. Choice: " << endl;
        cout << "1: A game of chess" << endl;
        cin >> menuSelection;
        if (menuSelection == 0){
            exit = true;
        }
        else if (menuSelection == 1){
            bool gameFinished = false;
            chessBoard newBoard;
            newBoard.getBoard();
            cout << endl;
            cout << "Enter player one's name: ";
            cin >> playerOneName;
            cout << endl;
            cout << "Enter player two's name: ";
            cin >> playerTwoName;
            cout << endl;
            
            cout << "START!" << endl;
            newBoard.setUpBoard();
            cout << "Please enter which piece you would like to move by coordinates." << endl;
            
            cout << "Example: \"Move piece \" 1A \" to \"2A\"." << endl;
            
            while (gameFinished != true){
                int rowPre;
                int columnPre;
                int rowAfter;
                int columnAfter;
                int playerNumber;
                bool playerOne = true;
                bool playerTwo = true;
                
                
                
                while (playerOne == true){
					playerNumber = 1;
					newBoard.getBoard();
					string moveStringPre = "";
					string moveStringAfter = "";
					cout << playerOneName << " move piece ";
					cin>> moveStringPre;
					
					cout << " to ";
					cin>> moveStringAfter;
					newBoard.getMoveSpot(moveStringPre, moveStringAfter,rowPre, columnPre, rowAfter, columnAfter);
					playerOne = newBoard.movePiece(playerNumber, rowPre, columnPre, rowAfter, columnAfter);				
					
					
				}
				
				while (playerTwo ==  true){
					playerNumber = 2;
					newBoard.getBoard();
					string moveStringPre = "";
					string moveStringAfter = "";
					cout << playerTwoName << " move piece ";
					cin>> moveStringPre;
                
					cout << " to ";
					cin>> moveStringAfter;
					newBoard.getMoveSpot(moveStringPre, moveStringAfter,rowPre, columnPre, rowAfter, columnAfter);
					playerTwo = newBoard.movePiece(playerNumber, rowPre, columnPre, rowAfter, columnAfter);				
					
					
				}
				
                
            }
            
            
            newBoard.getBoard();
        }
        else{
            cout << "Please enter a valid choice. Try again." << endl;
        }
    }
    
    return 0;
}
