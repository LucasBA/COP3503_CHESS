#ifndef CHESSPROJECT_H
#define CHESSPROJECT_H

#include <iostream>
#include <string>

using namespace std;

class chessBoard{
private:
    string board [9] [9];
    
public:
    chessBoard(){
        for (int row = 1; row < 9; row++){
            for (int column = 0; column < 1; column++){
                string rowNumbers[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};
                board [row] [column] = rowNumbers[row - 1];
            }
        }
        for (int column = 1; column < 9; column++){
            for (int row = 0; row < 1; row++){
                string columnLetters[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};
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
            string playerOnePieces[8] = {"R1", "KN1", "B1", "Q1", "K1", "B1", "KN1", "R1"};
            board [1] [column] = playerOnePieces[column - 1];
        }
        for (int column = 1; column < 9 ; column++){
            string playerOnePieces[8] = {"P1", "P1", "P1", "P1", "P1", "P1", "P1", "P1"};
            board [2] [column] = playerOnePieces[column - 1];
        }
        for (int column = 1; column < 9 ; column++){
            string playerTwoPieces[8] = {"P2", "P2", "P2", "P2", "P2", "P2", "P2", "P2"};
            board [7] [column] = playerTwoPieces[column - 1];
        }
        for (int column = 1; column < 9 ; column++){
            string playerTwoPieces[8] = {"R2", "KN2", "B2", "Q2", "K2", "B2", "KN2", "R2"};
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
                if (board [i] [j] == "K1"){
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
                if (board [i] [j] == "K1"){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
    
    void movePiece(int rowPre, int columnPre, int rowAfter, int columnAfter){
        if (this -> legalityOfMove(rowPre, columnPre, rowAfter, columnAfter) == true){
            board [rowAfter] [columnAfter] = board [rowPre] [columnPre];
            board [rowPre] [columnPre] = "SPACE";
        }
    }
    
    bool legalityOfMove(int rowPre, int columnPre, int rowAfter, int columnAfter){
        
        string piece = board [rowPre] [columnPre];
        
        //Check to see if own piece is at the after point
        //if (
        if (piece == "P1"){
            if (this -> pawnConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true){
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
                    return true;
                }
            }
            
            return false;
        }
        else if (piece == "KN1" || piece == "KN2") {
            if (this->knightConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                return true;
            }
            return false;
        }
        else if (piece == "R1" || piece == "R2") {
            if (this->rookConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
                    return true;
                }
            }
            return false;
        }
        else if (piece == "B1" || piece == "B2") {
            if (this->bishopConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
                    return true;
                }
            }
            return false;
        }
        else if (piece == "Q1" || piece == "Q2") {
            if (this->queenConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                if(this -> isPathClear(rowPre, columnPre, rowAfter, columnAfter)){
                    return true;
                }
            }
            return false;
        }
        else if (piece == "K1" || piece == "K2") {
            if (this->kingConstraintsP1(rowPre, columnPre, rowAfter, columnAfter) == true) {
                return true;
            }
            return false;
        }
        if (piece == "P2") {
            if (this->pawnConstraintsP2(rowPre, columnPre, rowAfter, columnAfter) == true) {
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
        string playerOneString = "";
        
        parsingNameOfPiece = board [rowPre] [columnPre];
        playerOneString = parsingNameOfPiece.find("1");
        
        if (playerOneString == "1"){
            return true;
        }
        return false;
        
    }
    
    bool pieceP2(int rowPre, int columnPre){
        string parsingNameOfPiece;
        string playerOneString = "";
        
        parsingNameOfPiece = board [rowPre] [columnPre];
        playerOneString = parsingNameOfPiece.find("2");
        
        if (playerOneString == "2"){
            return true;
        }
        return false;
    }
    
    bool pawnConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter){ //Still needs to check if pieces are in the way
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow == 2 && columnPre == columnAfter) {
            if (rowPre == 2 && columnPre == columnAfter) {
                return true;
            }
        }
        else if (logicMoveRow == 1 && board [rowAfter] [columnAfter] != "SPACE" && (logicMoveColumn == 1 || logicMoveColumn == -1)){
            return true;
            //May need to check to see if opponents piece is taken.
        }
        else if (logicMoveRow == 1 && columnPre == columnAfter){
            return true;
        }
        return false;
    }
    
    bool knightConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow == 2 && logicMoveColumn == 1) {
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
    
    bool rookConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if pieces are in the way and if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow > 0 && logicMoveRow <= 7 && columnAfter == columnPre) {
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
    
    bool bishopConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if pieces are in the way and if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveRow >= 1 && logicMoveRow <= 7 && logicMoveColumn == logicMoveRow) {
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
    
    bool queenConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if pieces are in the way and if piece was taken
        return true;
    }
    
    bool kingConstraintsP1(int rowPre, int columnPre, int rowAfter, int columnAfter) { //Still needs check if pieces are in the way and if piece was taken
        int logicMoveRow;
        int logicMoveColumn;
        
        logicMoveRow = rowAfter - rowPre;
        logicMoveColumn = columnAfter - columnPre;
        
        if (logicMoveColumn == 1 || logicMoveRow == 1 || logicMoveColumn == -1 || logicMoveRow == -1) {
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
            if (rowPre == 7 && columnPre == columnAfter) {
                return true;
            }
        }
        else if (logicMoveRow == -1 && board[rowAfter][columnAfter] != "SPACE" && (logicMoveColumn == 1 || logicMoveColumn == -1)) {
            return true;
            //May need to check to see if opponents piece is taken.
        }
        else if (logicMoveRow == -1 && columnPre == columnAfter) {
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
                    for(int j = columnPre - 1; j > columnAfter; j--){
                        if(board [i] [j] != "SPACE"){
                            cout<< "Illegal move, piece in the way!\n";
                            return false;
                        }
                    }
                    
                }
            }
            
            // check movement down and to the right
            else if (columnAfter > columnPre){
                for(int i = rowPre + 1; i < rowAfter; i++){
                    for(int j = columnPre + 1; j > columnAfter; j++){
                        if(board [i] [j] != "SPACE"){
                            cout<< "Illegal move, piece in the way!\n";
                            return false;
                        }
                    }
                    
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
