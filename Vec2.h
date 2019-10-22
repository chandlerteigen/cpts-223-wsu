/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 10-18-19
 * Description: This project was created to fulfill the assignment PA4
 * 				for CPTS 223 at WSU fall 2019.
 * Notes: The code from TestBoard.cpp was adapted from code provided by
 * 		  the assignment.
************************************************************************/

#ifndef VEC2_H
#define VEC2_H

#include <iostream>

class Vec2
{
public:
    Vec2(int new_x = 0, int new_y = 0);
    ~Vec2();

    // accessors
    int get_x() const;
    int get_y() const;
    //mutators
    void set_x(int new_x);
    void set_y(int new_y);
    
    /**************************************************************************************
     * Function: is_vertical
     * Arguments: const Vec2
     * Returns: bool
     * Description: determines if the calling Vec2 is in vertical alignment with the argument
     *              Vec2 other. returns true if vertically aligned, false if not, or if
     *              equal.
     * ************************************************************************************/
    bool is_vertical(const Vec2 other) const;

    /**************************************************************************************
     * Function: is_horizontal
     * Arguments: const Vec2
     * Returns: bool
     * Description: determines if the calling Vec2 is in horizontal alignment with the argument
     *              Vec2 other. returns true if horizontally aligned, false if not, or if
     *              equal.
     * ************************************************************************************/
    bool is_horizontal(const Vec2 other) const;

    /**************************************************************************************
     * Function: is_diagonal
     * Arguments: const Vec2
     * Returns: bool
     * Description: determines if the calling Vec2 is diagonally aligned with the argument
     *              Vec2 other. returns true of diagonal, false if not, or if equal.
     * ************************************************************************************/
    bool is_diagonal(const Vec2 other) const;

    /**************************************************************************************
     * Function: Vec2::operator=
     * Arguments: Vec2 &
     * Returns: Vec2 &
     * Description: overloaded assignment operator for Vec2 class. sets the rhs members x
     *              and y to the same values as the called Vec2's members x and y. returns
     *              a reference to the lhs to allow operator chaining.
     * ************************************************************************************/
    Vec2 &operator= (Vec2 &rhs);

    /**************************************************************************************
     * Function: Vec2::operator<
     * Arguments: const Vec2 &
     * Returns: bool
     * Description: overloaded < operator for Vec2 class. compares member x first. if the x
     *              members are equal, the y members are compared.
     * ************************************************************************************/
    bool operator< (const Vec2 &rhs) const;

private:
    int x, y;
};

/**************************************************************************************
 * Function: operator-   //for Vec2
 * Arguments: const Vec2 &, const Vec2 &
 * Returns: Vec2
 * Description: subtracts the rhs x, and y members from the lhs x and y members 
 *              respectively. returns a Vec2 with the resultant x and y values.
 * ************************************************************************************/
Vec2 operator- (const Vec2 &lhs, const Vec2 &rhs);

/**************************************************************************************
 * Function: operator==     //for Vec2
 * Arguments: const Vec2 &, const Vec2 &
 * Returns: bool
 * Description: overloaded == operator.compares the x and y members of each argument Vec2. 
 *              returns true if both are equal to the corresponding members of the other 
 *              Vec2. returns false otherwise.
 * ************************************************************************************/
bool operator== (const Vec2 &lhs, const Vec2 &rhs);


/**************************************************************************************
 * Function: operator<<     //for stream insertion of Vec2
 * Arguments: std::ostream &, const Vec2 &
 * Returns: std::ostream &
 * Description: overloaded stream insertion operator for Vec2. inserts x and y members
 *              along with labels. returns a reference to the std::ostream to allow
 *              chaining.
 * ************************************************************************************/
std::ostream &operator<< (std::ostream &lhs, const Vec2 &rhs);



#endif