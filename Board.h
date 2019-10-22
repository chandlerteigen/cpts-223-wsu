/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 10-18-19
 * Description: This project was created to fulfill the assignment PA4
 * 				for CPTS 223 at WSU fall 2019.
 * Notes: The code from TestBoard.cpp was adapted from code provided by
 * 		  the assignment.
************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <set>
#include "Player.h"
#include "Vec2.h"

class Board
{
public:
    Board();
    ~Board();

    // accessors
    int get_num_players() const;
    int get_board_dim() const;

    // mutators
    void set_num_players(int new_num_players);
    void set_board_dim(int new_board_dim);
    /**************************************************************************************
     * Function: is_in_bounds
     * Arguments: Vec2
     * Returns: bool
     * Description: checks if the inputted Vec2 is within the boundaries of the board based
     *              on the value of board_dim and the x,y members of the Vec2.
     * ************************************************************************************/
    bool is_in_bounds(Vec2 position);

    /**************************************************************************************
     * Function: is_occupied
     * Arguments: Vec2 position
     * Returns: bool
     * Description: checks if the new_ID already exists in the std::set playres, if the 
     *              Vec2 new_position already exists in the std::set occupied_positions and 
     *              if the num_players is greater than board_dim. If all are false, the 
     *              player is added to players and the position is added to occupied positions.
     *              num_players is incrememented. returns true if player successfullu added
     * ************************************************************************************/
    bool is_occupied(Vec2 position);


    /**************************************************************************************
     * Function: insert_player
     * Arguments: unsigned int, Vec2
     * Returns: bool
     * Description: checks if the new_ID already exists in the std::set playres, if the 
     *              Vec2 new_position already exists in the std::set occupied_positions and 
     *              if the num_players is greater than board_dim. If all are false, the 
     *              player is added to players and the position is added to occupied positions.
     *              num_players is incrememented. returns true if player successfullu added
     * ************************************************************************************/
    bool insert_player(unsigned int new_ID, int x, int y);

    /**************************************************************************************
     * Function: removed_player
     * Arguments: unsigned int
     * Returns: bool
     * Description: checks if the player_ID exists in std::set players, if it does, it stores
     *              the Player's Vec2 position, then erases the player from players, and 
     *              erases the position from occupied positions. returns true if a player
     *              was removed.
     * ************************************************************************************/
    bool remove_player(unsigned int player_ID);

    /**************************************************************************************
     * Function: find_player
     * Arguments: unsigned int
     * Returns: bool
     * Description: checks if the player_ID exists in the std::set players. If it does,
     *              true is returned. returns false otherwise.
     * ************************************************************************************/
    bool find_player(unsigned int player_ID);

    /**************************************************************************************
     * Function: move_player
     * Arguments: unsigned int, Vec2
     * Returns: bool
     * Description: takes an unsigned int player_ID and Vec2 new_location as input, checks
     *              that the location is valid, and moves the player if it is. removes a 
     *              player if it was at the new location.
     * ************************************************************************************/
    bool move_player(unsigned int player_ID, int x, int y);

    /**************************************************************************************
     * Function: print_by_ID
     * Arguments: void
     * Returns: void
     * Description: prints each player in std::set players to the console using the overloaded
     *              stream insertion operator for players. The ID and position are printed.
     * ************************************************************************************/
    void print_by_ID() const;

private:

    int num_players;    // number of players currently on the board
    int board_dim;      // side dimension of the square board. Also max number of players
    std::set<Player> players;   // std::set containing all current Player objects sorted by ID
    //std::set<Vec2> occupied_positions;  // std::set containing occupied positions
    std::set<Player, Player_Vec2_less> occupied_positions; // sorted by Vec2 position

};


#endif