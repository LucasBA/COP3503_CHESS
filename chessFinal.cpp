#include "chessFinal.h"

#include <iostream>
#include <string>

//To avoid the excess use of standard
using namespace std;

//The chess game's main class
int main(){
	
	//menu slection area
    bool exit = false;
    int menuSelection;
    string playerOneName;
    string playerTwoName;

	//The main loop for the entire menu
    while (exit != true){
		
		//The menu output setup
		cout << "\n\n\n";
        cout << "MAIN MENU" << endl;
        cout << endl;
        cout << "*** PLEASE SET THE SCREEN TO MAX FOR OPTIMUM VIEWING ***" << "\n\n\n";
        cout << "Please select an option (1, 2, 0). Choice: " << endl;
        cout << endl;
        cout << "1: Rules of chess" << endl;
        cout << "2: A game of chess" << endl;
        cout << "0: Exit" << endl;
        cout << endl;
        cin >> menuSelection; // Menu input
        
        //the other way to exit instead of ctrl c
        if (menuSelection == 0){
            exit = true;
        }
        
        //Leads to the chess rules
        else if (menuSelection == 1) {
			
			//Chess rule options
			int chessrules;
			
			//Loop for navigating through chess rule menu
			while (chessrules != 4){
				
				//State what each choces are
				cout << endl;
				cout << "RULES OF CHESS \n" << endl;
				cout << "Please choose an option" << endl;
				cout << "1. Basic Rules" << endl;
				cout << "2. Basic Movement" << endl;
				cout << "3. Check" << endl;
				cout << "4. Return to MAIN MENU" << endl;
				cout << "\nChoice: ";
				cin >> chessrules;

				if (chessrules == 1) {
					cout << endl;
					cout << "BASIC RULES" << endl;
					cout << "Player one moves first, then players alternate moves." << endl;
					cout << "Making a move is required." << endl;
					cout << "It is not legal to skip a move, even when having to move is detrimental." << endl;
					cout << "Play continues until a king is checkmated or a draw is declared. \n" << endl;
					cout << "Checkmate:" << endl;
					cout << "If a player's king is placed in check and there is no legal move that player can make to escape check, then the king is said to be checkmated, the game ends, and that player loses." << endl;
					cout << "Unlike other pieces, the king is never actually captured or removed from the board because checkmate ends the game. \n" << endl;
					cout << "Draws:" << endl;
					cout << "The game is automatically a draw if the player to move is not in check but has no legal move." << endl;
					cout << "The game is immediately drawn when there is no possibility of checkmate for either side with any series of legal moves." << endl;
					cout << "\t King against king" << endl;
					cout << "\t King against king and bishop" << endl;
					cout << "\t King against king and knight" << endl;
					cout << "\t King and bishop against king and bishop, with both bishops on squares of the same color" << endl;
					cout << "The game is a draw if a player only has a king left and cannot checkmate within 10 moves." << endl;
				}

				else if (chessrules == 2) {
					cout << endl;
					cout << "Basic Movement" << endl;
					cout << endl;
					cout << "King:" << endl;
					cout << "\t The king moves exactly one square horizontally, vertically, or diagonally." << endl;
					cout << "\t Once per game, the king is allowed to do a special move called castling. " << endl;
					cout << "\t Castling consists of moving the king two squares towards a rook, then placing the rook on the other side of the king, adjacent to it." << endl;
					cout << "\t Castling is only permissible if all of the following conditions hold:" << endl;
					cout << "\t \t The king and rook involved in castling must not have previously moved" << endl;
					cout << "\t \t There must be no pieces between the king and the rook" << endl;
					cout << "\t \t The king may not currently be in check, nor may the king pass through or end up in a square that is under attack by an enemy piece" << endl;
					cout << "\t \t The rook is permitted to be under attack and to pass over an attacked square" << endl;
					cout << "\t \t The king and the rook must be on the same rank." << endl;

					cout << endl;
					cout << "Rook:" << endl;
					cout << "\t A rook moves any number of vacant squares in a horizontal or vertical direction." << endl;

					cout << endl;
					cout << "Bishop:" << endl;
					cout << "\t A bishop moves any number of vacant squares in any diagonal direction." << endl;

					cout << endl;
					cout << "Queen:" << endl;
					cout << "\t The queen moves any number of vacant squares in a horizontal, vertical, or diagonal direction." << endl;

					cout << endl;
					cout << "Knight:" << endl;
					cout << "\t A knight moves to the nearest square not on the same rank, file, or diagonal." << endl;
					cout << "\t The knight is not blocked by other pieces: it jumps to the new location." << endl;

					cout << endl;
					cout << "Pawn:" << endl;
					cout << "\t A pawn moves straight forward one square, if that square is vacant." << endl;
					cout << "\t If it has not yet moved, a pawn also has the option of moving two squares straight forward, provided both squares are vacant." << endl;
					cout << "\t Pawns cannot move backwards." << endl;
					cout << "\t A pawn can capture an enemy piece on either of the two squares diagonally in front of the pawn." << endl;
					cout << "\t If a player advances a pawn to its eighth rank, the pawn is then promoted (converted) to a queen, rook, bishop, or knight of the same color at the choice of the player." << endl;
				}

				else if (chessrules == 3) {
					cout << endl;
					cout << "Check" << endl;
					cout << endl;
					cout << "A king is in check when it is under attack by at least one enemy piece." << endl;
					cout << "A piece unable to move because it would place its own king in check (it is pinned against its own king) may still deliver check to the opposing player." << endl;
					cout << "A player may not make any move which places or leaves his king in check." << endl;
					cout << "The possible ways to get out of check are:" << endl;
					cout << "\t Move the king to a square where it is not threatened" << endl;
					cout << "\t Capture the threatening piece (possibly with the king)" << endl;
					cout << "\t Block the check by placing a piece between the king and the opponent's threatening piece" << endl;
					cout << "If nothing can be done, then the king is checkmated and the game is over." << endl;
				}
				else if (chessrules == 4){
				}
				
				//exit
				else{
					cout <<"Please enter a choice between 1-4. The choice 4 to exit" << endl;
				}
			}
		}
		
		//This is the area for the actual game
        else if (menuSelection == 2){
			
            bool gameFinished = false;
            chessBoard newBoard;
            newBoard.getBoard();
            
            cout << endl;
            cout << "Enter player one's name: ";
            cin >> playerOneName; //enters playerone name
            cout << endl;
            cout << "Enter player two's name: ";
            cin >> playerTwoName; //enter player two name
            cout << endl;
            
            cout << "\t\t\t\t-START-" << endl;
            cout << endl;
            
            newBoard.setUpBoard(); //Picecs are set up
            
            cout << "Please enter which piece you would like to move by coordinates." << endl;            
            cout << "Example: \"Move piece \"1a\" to \"2a\"." << endl;
            cout << "To castle, please move the desired King piece to the spot" << endl;
            cout << "\n\n";
            
            //GAME START
            int playerNumber = 1;
            
            //Loop for changing between players
            while (gameFinished != true){
                int rowPre;
                int columnPre;
                int rowAfter;
                int columnAfter;
                bool moveChecker = false;
                
                newBoard.getBoard();
                
                //Player num 1
                if(playerNumber == 1){
					
					string moveStringPre = "";
					string moveStringAfter = "";
					
					cout << playerOneName << " move piece ";
					cin>> moveStringPre;
				
					cout << "to ";
					cin>> moveStringAfter;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";	
					
					//Input validation of spot of piece		
					if (!newBoard.getMoveSpot(moveStringPre, moveStringAfter,rowPre, columnPre, rowAfter, columnAfter)){
						cout << "Invalid Input.\n";
						continue;				
					}
					
					//Input validation of move of piece		
					if(!newBoard.movePiece(playerNumber, rowPre, columnPre, rowAfter, columnAfter)){
						cout << "Invalid move\n";
						continue;
					}
					
					//Checking for checkmate
					if (newBoard.check() == 2){
					cout << "Player 2 is in check" << endl;
					}
					
					else if (newBoard.check() == 4){
						cout << "Checkmate. " << playerOneName << " wins!" << endl;
						gameFinished = true;
						newBoard.getBoard();
						continue;
					}
					
					else if (newBoard.check() == 6){
						cout << "No possible moves left. The game is a tie!\n";
					}
					
					//TO the next player
					playerNumber++;
					continue;
				}
				
				//Player two options
				if(playerNumber == 2){
					
					string moveStringPre = "";
					string moveStringAfter = "";
					
					cout << playerTwoName << " move piece ";
					cin>> moveStringPre;
				
					cout << "to ";
					cin>> moveStringAfter;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					
					//Input validation of spot of piece	
					if (!newBoard.getMoveSpot(moveStringPre, moveStringAfter,rowPre, columnPre, rowAfter, columnAfter)){
						cout << "Invalid input.\n";
						continue;			
					}
					
					//Input validation of move of piece	
					if(!newBoard.movePiece(playerNumber, rowPre, columnPre, rowAfter, columnAfter)){
						cout << "Invalid move\n";
						continue;
					}
					
					//Checking for checkmate functions 
					if (newBoard.check() == 2){
					cout << "Player 1 is in check" << endl;
					}
					else if (newBoard.check() == 3){
						cout << "Checkmate. " << playerTwoName << " wins!" << endl;
						gameFinished = true;
						newBoard.getBoard();
						continue;
					}
					else if (newBoard.check() == 5){
						cout << "No possible moves left. The game is a tie!\n";
					}
					
					//TO the next player
					playerNumber--;
					continue;
				}
                
            }
            
        }
        
        //Input validation
        else{
            cout << "Please enter a valid choice. Try again." << endl;
        }
    }
    
    //exit
    return 0;
}
