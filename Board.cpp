/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 10-18-19
 * Description: This project was created to fulfill the assignment PA4
 * 				for CPTS 223 at WSU fall 2019.
 * Notes: The code from TestBoard.cpp was adapted from code provided by
 * 		  the assignment.
************************************************************************/
#include "Board.h"
#include <iostream>

Board::Board()
{
    do
    {
        std::cout << "Please enter the dimension of the square board (integer > 0): ";
        std::cin >> board_dim;
    } while (board_dim <= 0);
}

Board::~Board() {}

int Board::get_num_players() const { return num_players; }
int Board::get_board_dim() const { return board_dim; }

void Board::set_num_players(int new_num_players)
{
    num_players = new_num_players;
}

void Board::set_board_dim(int new_board_dim)
{
    board_dim = new_board_dim;
}

bool Board::is_in_bounds(Vec2 position)
{
    int result = true;

    if (position.get_x() > board_dim - 1) // x is out of bounds
        result = false;
    else if (position.get_y() > board_dim - 1) // y is out of bounds
        result = false;

    return result;
}

bool Board::insert_player(unsigned int new_ID, int x, int y)
{
    bool result = false;
    Vec2 new_position(x,y);
    Player new_player(new_position, new_ID); // temp player object
    if(this->is_in_bounds(new_position))
    {

        if(players.find(new_player) == players.end()) // if ID not found
        {
            if (occupied_positions.find(new_player) == occupied_positions.end()) // if position not found
            {
                if (num_players <= board_dim) // if board not at player limit
                {
                players.insert(new_player);
                occupied_positions.insert(new_player);
                num_players++;
                result = true;
                }
            }
            else
                std::cout << "Player with that position already exists..." << std::endl;
            
        }
        else
            std::cout << "Player with that ID already exists..." << std::endl;
        
    }
    else
    {
        std::cout << "Player cannot be inserted out of bounds... " << std::endl;
    }
    
    return result;
}

bool Board::remove_player(unsigned int player_ID)
{
    bool result = false;
    Vec2 pos; //temp Vec2 to create temp player
    Player temp_player(pos, player_ID); // temp player object to search Board::players
    auto player_to_remove = players.find(temp_player); // pointer to player to remove
    
    Player player_to_remove2 = *player_to_remove;
    if (player_to_remove != players.end()) // pointer indicates player not found
    {
        players.erase(player_to_remove); // erase player and position
        occupied_positions.erase(player_to_remove2);
        num_players--;
        result = true;
    }

    return result;
}

bool Board::find_player(unsigned int player_ID)
{
    bool result = false;
    Vec2 pos; // temp Vec2 to make temp player
    Player temp_player(pos, player_ID); // temp player for searching

    if (players.find(temp_player) != players.end()) // if found return true
        result = true;
    
    return result;
}

bool Board::move_player(unsigned int player_ID, int x, int y)
{
    bool result = false;
    Vec2 new_location(x,y);
    Player player_after_move(new_location, player_ID);
    if(this->is_in_bounds(new_location))
    {
        if(find_player(player_ID))
        {
            auto player_before_move = players.find(player_after_move);
            bool diag = new_location.is_diagonal(player_before_move->get_position());
            bool vert = new_location.is_vertical(player_before_move->get_position());
            bool hori = new_location.is_horizontal(player_before_move->get_position());
            if (diag || vert || hori) // move is valid
            {
                auto player_in_position = occupied_positions.find(player_after_move);
                if (player_in_position != occupied_positions.end()) // position occupied
                {
                    std:: cout << "Player Removed: " << *player_in_position << std::endl;
                    players.erase(*player_in_position);
                    occupied_positions.erase(*player_in_position);
                }
                players.erase(*player_before_move);
                occupied_positions.erase(*player_before_move);
                players.insert(player_after_move);
                occupied_positions.insert(player_after_move); 
            }
            else
            {
                std::cout << "Move was not straight or diagonal..." << std::endl;
            }
            
        }
        else
        {
            std::cout << "Player does not exist..." << std::endl;
        }
        
    }
    else
    {
        std::cout << "Move was out of bounds..." << std::endl;
    }
    
}

void Board::print_by_ID() const
{
    auto iter = players.begin();
    for(; iter != players.end(); iter++) // iterate through std::set and print contents
    {
        std::cout << *iter << std::endl;
    }
    std::cout << std::endl;
}

