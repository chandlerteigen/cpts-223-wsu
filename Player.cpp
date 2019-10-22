/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 10-18-19
 * Description: This project was created to fulfill the assignment PA4
 * 				for CPTS 223 at WSU fall 2019.
 * Notes: The code from TestBoard.cpp was adapted from code provided by
 * 		  the assignment.
************************************************************************/

#include "Player.h"



Player::Player(Vec2 new_position, unsigned int new_ID)
{
    ID = new_ID;
    position = new_position;

}


Player::~Player() {}

unsigned int Player::get_ID() const { return ID; }
Vec2 Player::get_position() const { return position; }

void Player::set_position(Vec2 new_position)
{
    position = new_position;
}

bool Player::operator< (const Player &rhs) const
{
    return this->get_ID() < rhs.get_ID();
}

std::ostream &operator<< (std::ostream &lhs, const Player &rhs)
{
    std::cout << "ID: " << rhs.get_ID() << "    Position: " << rhs.get_position();
    return lhs;
}

bool Player_Vec2_less::operator() (const Player &lhs, const Player &rhs) const
{
    return lhs.get_position() < rhs.get_position();
}