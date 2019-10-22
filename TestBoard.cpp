/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 10-18-19
 * Description: This project was created to fulfill the assignment PA4
 * 				for CPTS 223 at WSU fall 2019.
 * Notes: The code from TestBoard.cpp was adapted from code provided by
 * 		  the assignment. The comment above main in TestBoard.cpp shows the
 * 		  linux command to compile the code.
************************************************************************/



#include "Board.h"

/*
Compile using:
g++ TestBoard.cpp Player.cpp Vec2.cpp Board.cpp -o ex

Run using:
./ex
*/

int main() {

	// This code is not a complete test code (won't even compile) and it may be syntactically inconsistent with your class definitions. 
	// So modify before use as appropriate. But the idea of testing should be clear. You are free to shuffle around the order of operations in order to devise more test cases of your own.


	Board B;	// specifies that the game board size is 1000000 x 1000000 

	// the following is a sequence of calls to Board class methods assuming
	// 	the input example (m=10,n=8) given in the programming assignment.

	B.insert_player(1,3,2);	// assumed syntax: Insert(ID, x, y)
	B.insert_player(2,4,3);
	B.insert_player(3,4,6);
	B.insert_player(4,5,7);
	B.insert_player(5,6,3);
	B.insert_player(6,8,2);
	B.insert_player(7,9,3);
	B.insert_player(8,9,8);
	B.print_by_ID();

	B.insert_player(3,7,6);	// should fail because player 3 is already there

	B.insert_player(10,9,8);	// should fail because 9,8 is occupied already
	
	B.move_player(4,9,3);	//assumed syntax: MoveTo(ID,x,y) // removes 7 in the process
	B.print_by_ID();

	B.move_player(4,9,8);	// removes 8
	B.print_by_ID();
	
	B.move_player(4,6,3); // should fail because move to 6,3 is from 4's current position is not valid
	B.print_by_ID();

	B.move_player(2,3,3);
	B.print_by_ID();

	B.move_player(4,3,2);	// removes 1
	B.print_by_ID();

	B.move_player(4,8,2);	// removes 6
	B.print_by_ID();

	B.move_player(5,3,3);	// removes 2
	B.print_by_ID();

	B.move_player(4,4,6);	// removes 3
	B.print_by_ID();

	B.move_player(5,4,3);	
	B.print_by_ID();

	B.move_player(4,4,3);	// removes 5
	B.print_by_ID();

	// the code should print only one player at this stage which is player 4 @ (4,3)
	
}