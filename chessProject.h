#ifndef CHESSPROJECT_H
#define CHESSPROJECT_H

#include <iostream>
#include <string>

using namespace std;
string addColor(string str, string color){
    if (color == "red"){
        return "\033[1;31m" + str + "\033[0m";
    }
    if (color == "blue"){
        return "\033[1;34m" + str + "\033[0m";
    }
    if (color == "green"){
        return "\033[1;32m" + str + "\033[0m";
    }
    if (color == "yellow"){
        return "\033[1;33m" + str + "\033[0m";
    }
    if (color == "magenta"){
        return "\033[1;35m" + str + "\033[0m";
    }
    if (color == "cyan"){
        return "\033[1;36m" + str + "\033[0m";
    }    
}
class chessBoard{
private:
    string board [9] [9];
    
public:
    chessBoard(){
        for (int row = 1; row < 9; row++){
            for (int column = 0; column < 1; column++){
                string rowNumbers[8] = {addColor("1","green"), addColor("2","green"),addColor("3","green"),addColor("4","green"),addColor("5","green"),addColor("6","green"),addColor("7","green"),addColor("8","green")};
                board [row] [column] = rowNumbers[row - 1];
                board [row] [column] = rowNumbers[row - 1];
            }
        }
        for (int column = 1; column < 9; column++){
            for (int row = 0; row < 1; row++){
                string columnLetters[8] = {addColor("A","green"), addColor("B","green"),addColor("C","green"),addColor("D","green"),addColor("E","green"),addColor("F","green"),addColor("G","green"),addColor("H","green")};
                board [row] [column] = columnLetters[column - 1];
            }
        }
        for (int row = 1; row < 9; row++){
            for (int column = 1; column < 9; column++){
                board [row] [column] = "SPACE";
            }
        }
    }
    
    void setUpBoard(){
        for (int column = 1; column < 9 ; column++){
            string playerOnePieces[8] = {addColor("R", "red"), addColor("KN", "red"), addColor("B", "red"), addColor("Q", "red"), addColor("K", "red"), addColor("B", "red"), addColor("KN", "red"), addColor("R", "red")};
            board [1] [column] = playerOnePieces[column - 1];
        }
        for (int column = 1; column < 9 ; column++){
            string playerOnePieces[8] = {addColor("P" , "red"), addColor("P" , "red"), 
                    addColor("P" , "red"), addColor("P" , "red"), addColor("P" , "red"), addColor("P" , "red"), 
                        addColor("P" , "red"), addColor("P" , "red")};
            board [2] [column] = playerOnePieces[column - 1];
        }
        for (int column = 1; column < 9 ; column++){
            string playerTwoPieces[8] = {addColor("P" , "blue"), addColor("P" , "blue"), 
                    addColor("P" , "blue"), addColor("P" , "blue"), addColor("P" , "blue"), 
                        addColor("P" , "blue"), addColor("P" , "blue"), addColor("P" , "blue")};
            board [7] [column] = playerTwoPieces[column - 1];
        }
        for (int column = 1; column < 9 ; column++){
            string playerTwoPieces[8] = {addColor("R", "blue"), addColor("KN", "blue"), addColor("B", "blue"), addColor("Q", "blue"), addColor("K", "blue"), addColor("B", "blue"), addColor("KN", "blue"), addColor("R", "blue")};
            board [8] [column] = playerTwoPieces[column - 1];
        }
    }
    
    
    void getBoard(){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << board [i] [j] << "\t";
            }
            cout << "\n\n\n";
        }
    }
    
    string getBoardPiece(int row, int column){
        return board [row] [column];
    }
    
    //Only if checkmate doesn't work, this code will be there
    bool checkForKingOne(){
        for (int i = 1; i < 9; i++){
            for (int j = 1; j < 8; j++){
                if (board [i] [j] == addColor("K", "red")){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
    
    //Only if checkmate doesn't work, this code will be there
    bool checkForKingTwo(){
        for (int i = 1; i < 9; i++){
            for (int j = 1; j < 8; j++){
                if (board [i] [j] == addColor("K", "blue")){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
    
    bool movePiece(int playerNumber, int rowPre, int columnPre, int rowAfter, int columnAfter){
        if (this -> legalityOfMove(playerNumber, rowPre, columnPre, rowAfter, columnAfter) == true){
            board [rowAfter] [columnAfter] = board [rowPre] [columnPre];
            board [rowPre] [columnPre] = "SPACE";
            return false;
        }
        return true;
    }
    
    bool legalityOfMove(int playerNumber, int rowPre, int columnPre, int rowAfter, int columnAfter){
        
        string piece = board [rowPre] [columnPre];
        
        //Check to see if own piece is at the after point
        //if (
        if (piece == addColor("P" , "red") && playerNumber == 1){
            if (this -> pawnConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true){
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
					if (this->pieceP1(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
						return false;
					}
                    return true;
                }
            }
            
            return false;
        }
        else if (piece == addColor("KN", "red") && playerNumber == 1) {
            if (this->knightConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->pieceP1(rowAfter, columnAfter)) {
					return false;
				}
                return true;
            }
            return false;
        }
        else if (piece == addColor("R", "red") && playerNumber == 1) {
            if (this->rookConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
					
					//Makes sure that P1's piece cannot take P1's piece
					if (this->pieceP1(rowAfter, columnAfter)) {		
						return false;
					}
                    return true;
                }
            }
            return false;
        }
        else if (piece == addColor("B", "red") && playerNumber == 1) {
            if (this->bishopConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
					if (this->pieceP1(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
						return false;
					}
                    return true;
                }
            }
            return false;
        }
        else if (piece == addColor("Q", "red") && playerNumber == 1) {
            if (this->queenConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
					if (this->pieceP1(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
						return false;
					}
                    return true;
                }
            }
            return false;
        }
        else if (piece == addColor("K", "red") && playerNumber == 1) {
            if (this->kingConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->pieceP1(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
					return false;
				}
                return true;
            }
            return false;
        }
        else if (piece == addColor("P" , "blue") && playerNumber == 2) {
            if (this->pawnConstraintsP2(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->isPathClear(rowPre, columnPre, rowAfter, columnAfter)) {
					if (this->pieceP2(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
						return false;
					}
					return true;
				}
            }
            return false;
        }
		else if (piece == addColor("KN", "blue") && playerNumber == 2) {
			if (this->knightConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->pieceP2(rowAfter, columnAfter)) {
					return false;
				}
				return true;
			}
			return false;
		}
		else if (piece == addColor("R", "blue") && playerNumber == 2) {
			if (this->rookConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->isPathClear(rowPre, columnPre, rowAfter, columnAfter)) {
					if (this->pieceP2(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
						return false;
					}
					return true;
				}
			}
			return false;
		}
		else if (piece == addColor("B", "blue") && playerNumber == 2) {
			if (this->bishopConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->isPathClear(rowPre, columnPre, rowAfter, columnAfter)) {
					if (this->pieceP2(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
						return false;
					}
					return true;
				}
			}
			return false;
		}
		else if (piece == addColor("Q", "blue") && playerNumber == 2) {
			if (this->queenConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->isPathClear(rowPre, columnPre, rowAfter, columnAfter)) {
					if (this->pieceP2(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
						return false;
					}
					return true;
				}
			}
			return false;
		}
		else if (piece == addColor("K", "blue") && playerNumber == 2) {
			if (this->kingConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
				if (this->pieceP2(rowAfter, columnAfter)) {		//Makes sure that P1's piece cannot take P1's piece.
					return false;
				}
				return true;
			}
			return false;
		}

        return false;
    }
    
    bool isPieceThere(int rowPre, int columnPre){
        if (board [rowPre] [columnPre] != "SPACE"){
            return true;
        }
        return false;
    }
    
    bool inputOutOfBounds(int rowPre, int columnPre){
        if (rowPre < 1 || columnPre < 1 || rowPre > 8 || columnPre > 8){
            cout << "Input out of bounds" << endl;
            return true;
        }
        return false;
    }
    
    bool outputOutOfBounds(int rowAfter, int columnAfter){
        if (rowAfter < 1 || columnAfter < 1|| rowAfter > 8 || columnAfter > 8){
            cout << "Output out of bounds" << endl;
            return true;
        }
        return false;
    }
    
    bool pieceP1(int rowPre, int columnPre){
        string parsingNameOfPiece;
        
        parsingNameOfPiece = board [rowPre] [columnPre];
        if (parsingNameOfPiece[5]*4==196){			//Check if color is red
            return true;
        }
        return false;
        
    }
    
    bool pieceP2(int rowPre, int columnPre){
        string parsingNameOfPiece;
        
        parsingNameOfPiece = board [rowPre] [columnPre];
        if (parsingNameOfPiece[5]*4==208){			//Check if color is blue
            cout<<"true";
            return true;
        }
        cout<<"false";
        return false;
    }
    
    bool pawnConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter){
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow == 2 && columnPre == columnAfter) {			//P1 pawns can move 2 spaces if they are at row 2
            if (rowPre == 2 && columnPre == columnAfter) {				
				if (pieceP2(rowAfter, columnAfter)) {					//Makes sure pawns can't take what's in front of them
					return false;
				}
                return true;
            }
        }
        else if (logicMoveRow == 1 && board [rowAfter] [columnAfter] != "SPACE" && (logicMoveColumn == 1 || logicMoveColumn == -1)){
            return true;
            //May need to check to see if opponents piece is taken.
        }
        else if (logicMoveRow == 1 && columnPre == columnAfter){		//Otherwise, they only move 1 space forward
			if (pieceP2(rowAfter, columnAfter)) {						//Makes sure pawns can't take what's in front of them
				return false;
			}
			return true;
        }
        return false;
    }
    
    bool knightConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow == 2 && logicMoveColumn == 1) {				//Knight can only move in an 'L' pattern
            return true;
        }
        else if (logicMoveRow == 2 && logicMoveColumn == -1) {
            return true;
        }
        else if (logicMoveRow == -2 && logicMoveColumn == 1) {
            return true;
        }
        else if (logicMoveRow == -2 && logicMoveColumn == -1) {
            return true;
        }
        return false;
    }
    
    bool rookConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow > 0 && logicMoveRow <= 7 && columnAfter == columnPre) {			//Rook can only change either column or row, up to 7 spaces
            return true;
        }
        else if (logicMoveRow >= -7 && logicMoveRow < 0 && columnAfter == columnPre) {
            return true;
        }
        else if (logicMoveColumn > 0 && logicMoveColumn <= 7 && rowAfter == rowPre) {
            return true;
        }
        else if (logicMoveColumn >= -7 && logicMoveColumn < 0 && rowAfter == rowPre) {
            return true;
        }
        return false;
    }
    
    bool bishopConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow >= 1 && logicMoveRow <= 7 && logicMoveColumn == logicMoveRow) {	//Bishop moves a horizontal distance equal to the vertical distance
            return true;
        }
        if (logicMoveRow <= -1 && logicMoveRow >= -7 && logicMoveColumn == logicMoveRow) {
            return true;
        }
        if (logicMoveRow >= 1 && logicMoveRow <= 7 && logicMoveColumn == -logicMoveRow) {
            return true;
        }
        if (logicMoveRow <= -1 && logicMoveRow >= -7 && logicMoveColumn == -logicMoveRow) {
            return true;
        }
        return false;
    }
    
    bool queenConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if piece was taken
        return true;
    }
    
    bool kingConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveColumn == 1 || logicMoveRow == 1 || logicMoveColumn == -1 || logicMoveRow == -1) {		//King can only move 1 space in any direction
            return true;
        }
        return false;
    }
    bool pawnConstraintsP2(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs to check if pieces are in the way
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow == -2 && columnPre == columnAfter) {
            if (rowPre == 7 && columnPre == columnAfter) {				//P2 pawns can move 2 spaces if they are at row 7
				if (pieceP1(rowAfter, columnAfter)) {					//Makes sure pawns can't take what's in front of them
					return false;
				}
				return true;
            }
        }
        else if (logicMoveRow == -1 && board[rowAfter][columnAfter] != "SPACE" && (logicMoveColumn == 1 || logicMoveColumn == -1)) {
            return true;
            //May need to check to see if opponents piece is taken.
        }
        else if (logicMoveRow == -1 && columnPre == columnAfter) {		//Otherwise, they only move 1 space forward
			if (pieceP1(rowAfter, columnAfter)) {						//Makes sure pawns can't take what's in front of them
				return false;
			}
			return true;
        }
        return false;
    }
    
    void check(){
        
    }
    
    void checkMate(){
        
    }
    void getMoveSpot(string moveStringPre, string moveStringAfter, int& rowPre, int& columnPre, int& rowAfter, int& columnAfter){
        if(moveStringPre.length() != 2 || moveStringPre.length() != 2){
            cout<< "Wrong format. Write one number and one letter like this: 1A.\n";
        }
        else{
            if((moveStringPre.substr(0,1)) == "1"){
                rowPre = 1;
            }
            else if((moveStringPre.substr(0,1)) == "2"){
                rowPre = 2;
            }
            else if((moveStringPre.substr(0,1)) == "3"){
                rowPre = 3;
            }
            else if((moveStringPre.substr(0,1)) == "4"){
                rowPre = 4;
            }
            else if((moveStringPre.substr(0,1)) == "5"){
                rowPre = 5;
            }
            else if((moveStringPre.substr(0,1)) == "6"){
                rowPre = 6;
            }
            else if((moveStringPre.substr(0,1)) == "7"){
                rowPre = 7;
            }
            else if((moveStringPre.substr(0,1)) == "8"){
                rowPre = 8;
            }
            
            if((moveStringAfter.substr(0,1)) == "1"){
                rowAfter = 1;
            }
            else if((moveStringAfter.substr(0,1)) == "2"){
                rowAfter = 2;
            }
            else if((moveStringAfter.substr(0,1)) == "3"){
                rowAfter = 3;
            }
            else if((moveStringAfter.substr(0,1)) == "4"){
                rowAfter = 4;
            }
            else if((moveStringAfter.substr(0,1)) == "5"){
                rowAfter = 5;
            }
            else if((moveStringAfter.substr(0,1)) == "6"){
                rowAfter = 6;
            }
            else if((moveStringAfter.substr(0,1)) == "7"){
                rowAfter = 7;
            }
            else if((moveStringAfter.substr(0,1)) == "8"){
                rowAfter = 8;
            }
            
            
            if((moveStringPre.substr(1,1) == "A") || (moveStringPre.substr(1,1) == "a")){
                columnPre = 1;
            }
            else if((moveStringPre.substr(1,1) == "B") || (moveStringPre.substr(1,1) == "b")){
                columnPre = 2;
            }
            else if((moveStringPre.substr(1,1) == "C") || (moveStringPre.substr(1,1) == "c")){
                columnPre = 3;
            }
            else if((moveStringPre.substr(1,1) == "D") || (moveStringPre.substr(1,1) == "d")){
                columnPre = 4;
            }
            else if((moveStringPre.substr(1,1) == "E") || (moveStringPre.substr(1,1) == "e")){
                columnPre = 5;
            }
            else if((moveStringPre.substr(1,1) == "F") || (moveStringPre.substr(1,1) == "f")){
                columnPre = 6;
            }
            else if((moveStringPre.substr(1,1) == "G") || (moveStringPre.substr(1,1) == "g")){
                columnPre = 7;
            }
            else if((moveStringPre.substr(1,1) == "H") || (moveStringPre.substr(1,1) == "h")){
                columnPre = 8;
            }
            
            if((moveStringAfter.substr(1,1) == "A") || (moveStringAfter.substr(1,1) == "a")){
                columnAfter = 1;
            }
            else if((moveStringAfter.substr(1,1) == "B") || (moveStringAfter.substr(1,1) == "b")){
                columnAfter = 2;
            }
            else if((moveStringAfter.substr(1,1) == "C") || (moveStringAfter.substr(1,1) == "c")){
                columnAfter = 3;
            }
            else if((moveStringAfter.substr(1,1) == "D") || (moveStringAfter.substr(1,1) == "d")){
                columnAfter = 4;
            }
            else if((moveStringAfter.substr(1,1) == "E") || (moveStringAfter.substr(1,1) == "e")){
                columnAfter = 5;
            }
            else if((moveStringAfter.substr(1,1) == "F") || (moveStringAfter.substr(1,1) == "f")){
                columnAfter = 6;
            }
            else if((moveStringAfter.substr(1,1) == "G") || (moveStringAfter.substr(1,1) == "g")){
                columnAfter = 7;
            }
            else if((moveStringAfter.substr(1,1) == "H") || (moveStringAfter.substr(1,1) == "h")){
                columnAfter = 8;
            }
        }
        
    }
    
    bool isPathClear(int rowPre, int columnPre, int rowAfter, int columnAfter){
        
        // check row movement down
        if((rowAfter > rowPre)){
            
            // check movement down
            if(columnAfter == columnPre){
                for(int i = rowPre + 1; i < rowAfter; i++){
                    if(board [i] [columnPre] != "SPACE"){
                        cout<< "Illegal move, piece in the way!\n";
                        return false;
                    }
                }
            }
            
            // check movement down and to the left
            else if (columnAfter < columnPre){
                for(int i = rowPre + 1; i < rowAfter; i++){
                    int j = columnPre - 1;
                        if(board [i] [j] != "SPACE"){
                            cout<< "Illegal move, piece in the way!\n";
                            return false;
                        }
                        
                    columnPre--;                    
                }
            }
            
            // check movement down and to the right
            else if (columnAfter > columnPre){
                for(int i = rowPre + 1; i < rowAfter; i++){
                    int j = columnPre + 1;
                    if(board [i] [j] != "SPACE"){
                        cout<< "Illegal move, piece in the way!\n";
                        return false;
                    }
                    columnPre++;                   
                    
                }
            }
        }
        
        // check row movement up
        else if((rowAfter < rowPre)){
            
            // check movement up
            if(columnAfter == columnPre){
                for(int i = rowPre - 1; i > rowAfter; i--){
                    if(board [i] [columnPre] != "SPACE"){
                        cout<< "Illegal move, piece in the way!\n";
                        return false;
                    }
                }
            }
            
            // check movement up and to the left
            else if (columnAfter < columnPre){
                for(int i = columnPre - 1; i > columnAfter; i--){
                    for(int j = rowPre - 1; j > rowAfter; j--){
                        if(board [i] [j] != "SPACE"){
                            cout<< "Illegal move, piece in the way!\n";
                            return false;
                        }
                    }
                    
                }
            }
            
            // check movement up and to the right
            else if (columnAfter > columnPre){
                for(int i = columnPre + 1; i > columnAfter; i--){
                    for(int j = rowPre - 1; j < rowAfter; j++){
                        if(board [i] [j] != "SPACE"){
                            cout<< "Illegal move, piece in the way!\n";
                            return false;
                        }
                    }
                    
                }
            }
        }
        
        // check movement only horizontally
        else if (rowAfter == rowPre){
            
            // check movement to the right
            if(columnAfter > columnPre){
                for(int j = columnPre + 1; j < columnAfter; j++){
                    if(board [rowPre] [j] != "SPACE"){
                        cout<< "Illegal move, piece in the way!\n";
                        return false;
                    }
                }
            }
            
            // check movement to the left
            else if (columnAfter < columnPre){
                for(int j = columnPre - 1; j > columnAfter; j--){
                    if(board [rowPre] [j] != "SPACE"){
                        cout<< "Illegal move, piece in the way!\n";
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//When a piece is taken away, it is taken away to this object
//When a pawn goes to the otherside, it can take one of the pieces
//placed in this object.

//There will be one for each player.

class takenPieces{
private:
    string chessPieces[16];
    
public:
    takenPieces(){
    }
};

#endif
