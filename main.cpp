// DAVINA TITUS
// CS 141 - PROGRAM DESIGN II
// PEG GAME - PROJECT 2
// THIS PROJECT IS THE DIGITAL VERSION OF THE PEG GAME WHERE THE USER CAN INPUT 3 LETTERS TO MAKE A MOVE AND ALSO CHECK IF THEY HAVE WON THE GAME
// 17TH FEBRUARY 2025

#include <iostream>
using namespace std;


//call out functions
int row(char peg);
int col(char peg);
void displayboard( );
bool validMove( char start, char middle , char end);
void makeMove(string move);
char getPeg(char peg);
void setPeg (char peg, char value);
bool checkWin();


// GLOBAL VARIABLES FOR THE PEG CHARS
char A= '.' ,B = 'T', C = 'T',D = 'T',
   E = 'T',F = 'T', G = 'T',H = 'T',I = 'T',
   J = 'T',K = 'T',L = 'T',M = 'T',N = 'T',O ='T';


// Getting the peg location
char getPeg( char peg) {
   switch ( peg) {
       case 'A': return A;
       case 'B': return B;
       case 'C': return C;
       case 'D': return D;
       case 'E': return E;
       case 'F': return F;
       case 'G': return G;
       case 'H': return H;
       case 'I': return I;
       case 'J': return J;
       case 'K': return K;
       case 'L': return L;
       case 'M': return M;
       case 'N': return N;
       default : return '.';
   }
}


//setting the peg with new value
void setPeg ( char peg, char value) {
   switch ( peg) {
           case 'A': A = value; break;
           case 'B': B = value; break;
           case 'C': C = value; break;
           case 'D': D = value; break;
           case 'E': E = value; break;
           case 'F': F = value; break;
           case 'G': G = value; break;
           case 'H': H = value; break;
           case 'I': I = value; break;
           case 'J': J = value; break;
           case 'K': K = value; break;
           case 'L': L = value; break;
           case 'M': M = value; break;
           case 'N': N = value; break;
           case 'O' : O = value; break;
           default: break;
       }
}


// FUNCTION TO MAKE A MOVE BASED ON THE USER INPUT
void makeMove(string move){
   for ( int i = 0 ; i < 3;i++){
       char peg;
       if (i < 2) {
           peg = '.';
       }
       else {
           peg = 'T';
       }


       if (move[i]=='A'){
           A = peg;
       }
       if    (move[i]=='B'){
           B = peg;
       }
       if   (move[i]=='C') {
           C = peg;
       }
       if    (move[i]=='D') {
           D = peg;
       }
       if   (move[i]=='E'){
           E = peg;
       }
       if    (move[i]=='F') {
           F = peg;
       }
       if  (move[i]=='G'){
           G = peg;
       }
       if   (move[i]=='H'){
           H = peg;
       }
       if  (move[i]=='I') {
           I = peg;
       }  
       if    (move[i]=='J') {
           J = peg;
       }     
       if    (move[i]=='K') {
           K = peg;
       }   
       if    (move[i]=='L') {
           L = peg;
       }
       if    (move[i]=='M') {
           M = peg;
       }
       if    (move[i]=='N') {
           N = peg;
       }
       if    (move[i]=='O') {
           O = peg;
       }         
   }
}


// FUNCTION TO DISPLAY THE BOARD 
void displayboard( ) {
   cout << "    " <<  A << "            A" << endl;
   cout << "   " << B << " " << C  << "          B C" << endl;
   cout << "  " << D  << " " << E  << " " << F  << "        D E F" << endl;
   cout << " " << G << " " << H  << " " << I   << " " << J  << "      G H I J" << endl;
   cout << "" << K  << " " << L  << " " << M  << " " << N  << " " << O  << "    K L M N O" << endl;
   }


//FUNCTION TO CHECK IF THE MOVE IS VALID   
bool validMove( char start, char middle , char end) {


   // INVALID IF ITS NOT IN THE RANGE OF A-O
   if (start < 'A' || start > 'O' || middle < 'A' || middle > 'O' || end < 'A' || end > 'O') {
       cout << "Move is not valid. Try again." << endl;
       return false;
   }


   if (start == '.' || middle == '.' || end == 'T') {
       return false;
   }


   if (start < 'A' || start > 'O' || middle < 'A' || middle > 'O' || end < 'A' || end > 'O') {
       cout << "Move is not valid. Try again." << endl;
       return false;
   }


   if ( (start =='K') && (middle == 'H') && (end == 'F')){
       cout << "Move is not valid. Try again." << endl;
       return false;
       }
  


   // if ( (start =='D') && (middle == 'E' ) && (end == 'F')&& ( F=='T')){
   //     cout << "Move is not valid. Try again." << endl;
   //     return false;
   //     }
  
   if (getPeg(end) != '.') {
       cout << "Move is not valid.  Try again." << endl;
       return false;
   }




   int startRow = row(start);
   int middleRow = row(middle);
   int endRow = row(end);


   int startCol = col(start);
   int middleCol = col(middle);
   int endCol = col(end);


   if ((startRow == middleRow && middleRow == endRow &&
       abs(startCol - middleCol) == 1 && abs(middleCol - endCol) == 1) ||
       (startCol == middleCol && middleCol == endCol &&
       abs(startRow - middleRow) == 1 && abs(middleRow - endRow) == 1) ||
       (abs(startRow - middleRow) == 1 && abs(middleRow - endRow) == 1 &&
       abs(startCol - middleCol) == 1 && abs(middleCol - endCol) == 1)) {
       return true;
   }


   if (abs(startRow - middleRow) == -1 && abs(middleRow - endRow) == -1 &&
      abs(startCol - middleCol) == -1 && abs ( middleCol - endCol) == -1){
       return false;
   }


   cout << "Move is not valid. Try again." << endl;
   return false;
   }


// FUNCTION TO CHECK IF THE USER HAS WON THE GAME
bool checkWin() {
   int pegCount = 0;
   if (A == 'T') pegCount++;
   if (B == 'T') pegCount++;
   if (C == 'T') pegCount++;
   if (D == 'T') pegCount++;
   if (E == 'T') pegCount++;
   if (F == 'T') pegCount++;
   if (G == 'T') pegCount++;
   if (H == 'T') pegCount++;
   if (I == 'T') pegCount++;
   if (J == 'T') pegCount++;
   if (K == 'T') pegCount++;
   if (L == 'T') pegCount++;
   if (M == 'T') pegCount++;
   if (N == 'T') pegCount++;
   if (O == 'T') pegCount++;


   return pegCount == 1;


}


int row(char peg) {
   if (peg >= 'K') {
       return 5;
   }
   else if (peg >= 'G') {
       return 4;
   }
   else if (peg >= 'D') {
       return 3;
   }
   else if (peg >= 'B') {
       return 2;
   }
   else if (peg == 'A') {
       return 1;
   }
   else {
       cout << "Error - row: Invalid peg: " << peg << endl;
       return -1;
   }
}


int col(char peg) {
   if (peg >= 'K') {
       return peg - 'K' + 1;
   }
   else if (peg >= 'G') {
       return peg - 'G' + 1;
   }
   else if (peg >= 'D') {
       return peg - 'D' + 1;
   }
   else if (peg >= 'B') {
       return peg - 'B' + 1;
   }
   else if (peg == 'A') {
       return 1;
   }
   else {
       cout << "Move is not valid. Try again." << peg << endl;
       return -1;
   }
}


// MAIN FUNCTION
int main() {
   string move;
   while (true) {


       //TO CHECK IF THE USER HAS WON THE GAME
       if (checkWin()) {
           cout << "You win! Congratulations!" << endl;
           return 0;
       }


       // DISPLAY THE BOARD
       displayboard();


       cout << "Enter move (for example FCA) or Q to quit: " << endl;
       cin >> move;


       // TO QUIT THE GAME
       if (move[0]=='Q') {
           return 0;
       }


       // CHECK THE LENGTH
       if (move.length() != 3) {
           cout << "Move is not valid. Try again." << endl;
           continue;
       }


       char startPeg = move[0];
       char middlePeg = move[1];
       char endPeg = move[2];


       //TO CHECK IF THE MOVE IS VALID AND MAKE THE MOVE
       if (validMove( startPeg, middlePeg, endPeg)) {
           makeMove( move);
       }
      
   }
}
