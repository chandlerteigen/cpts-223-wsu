/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 10-18-19
 * Description: This project was created to fulfill the assignment PA4
 * 				for CPTS 223 at WSU fall 2019.
 * Notes: The code from TestBoard.cpp was adapted from code provided by
 * 		  the assignment.
************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Vec2.h"
#include <iostream>

class Player
{
public:
    //constructor
    Player(Vec2 new_position, unsigned int new_ID);
    //destructor
    ~Player();
    //accessors
    unsigned int get_ID() const;
    Vec2 get_position() const;
    //mutators
    void set_position(Vec2 new_position);



    /**************************************************************************************
     * Function: Player::operator<
     * Arguments: const Player &
     * Returns: bool
     * Description: compares the ID members of the calling Player and the argument Player.
     *              returns true if called Player::ID is less then argument Player::ID
     * ************************************************************************************/
    bool operator< (const Player &rhs) const;

private:

    unsigned int ID;    //player ID for identification of players on board
    Vec2 position;      // position on board as x, y coordinate

};

/**************************************************************************************
 * Function: operator<<     //stream insertion for Player
 * Arguments: std::ostream &, const Player &
 * Returns: std::ostream &
 * Description: overloaded stream insertion operator for Player class. inserts ID to
 *              stream and inserts player::position to stream using Vec2::operator<<.
 *              values are labeled.
 * ************************************************************************************/
std::ostream &operator<< (std::ostream &lhs, const Player &rhs);

struct Player_Vec2_less
{
    bool operator() (const Player &lhs, const Player &rhs) const; 
};

#endif