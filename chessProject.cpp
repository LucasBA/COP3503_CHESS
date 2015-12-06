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
        cout << "Please select an option (1, 2, 0). Choice: " << endl;
        cout << "1: Rules of chess" << endl;
        cout << "2: A game of chess" << endl;
        cout << "0: Exit" << endl;
        cin >> menuSelection;
        if (menuSelection == 0){
            exit = true;
        }
        else if (menuSelection == 1) {
			int chessrules;
			while (chessrules != 4){
				
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
				else{
					cout <<"Please enter a choice between 1-4. The choice 4 to exit" << endl;
				}
			}
		}
        else if (menuSelection == 2){
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
				if (newBoard.check() == 2){
					cout << "Player 2 is in check" << endl;
				}
				else if (newBoard.check() == 4){
					cout << "Player 2, checkmate." << endl;
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
					newBoard.getMoveSpot(moveStringPre, moveStringAfter, rowPre, columnPre, rowAfter, columnAfter);
					playerTwo = newBoard.movePiece(playerNumber, rowPre, columnPre, rowAfter, columnAfter);				
					
					
				}
				if (newBoard.check() == 1){
					cout << "Player 1 is in check" << endl;
				}
				else if (newBoard.check() == 3){
					cout << "Player 1, checkmate." << endl;
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
