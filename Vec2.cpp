/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 10-18-19
 * Description: This project was created to fulfill the assignment PA4
 * 				for CPTS 223 at WSU fall 2019.
 * Notes: The code from TestBoard.cpp was adapted from code provided by
 * 		  the assignment.
************************************************************************/

#include "Vec2.h"
#include <iostream>
#include <math.h>

Vec2::Vec2(int new_x, int new_y)
{
    if(new_x >= 0 && new_y >= 0)
    {
    x = new_x;
    y = new_y;
    }
    else
    {
        std::cout << "Invalid coordinates entered" << std::endl;

        x = y = 0;
    }
}

Vec2::~Vec2(){} //default destructor

int Vec2::get_x() const { return x; }
int Vec2::get_y() const { return y; }

void Vec2::set_x(int new_x)
{
    x = new_x;
}

void Vec2::set_y(int new_y)
{
    y = new_y;
}


bool Vec2::is_vertical(const Vec2 other) const
{
    bool result = false;

    //vertically aligned and not in same position
    if (this->x == other.get_x() && this->y != other.get_y())
        result = true;

    return result;
}

bool Vec2::is_horizontal(const Vec2 other) const
{
    bool result = false;

    //horizontally aligned and not in same position
    if(this->y == other.get_y() && this->x != other.get_x())
        result = true;

    return result;
}

bool Vec2::is_diagonal(const Vec2 other) const
{
    bool result = false;
    Vec2 difference = *this - other; // find difference of two vectors
    // if the absolute value difference's coordinates are equal, the vecs are diagonal
    if (*this == other)
        result = false;

    // if absolute values of difference between vector equal, they are diagonal
    else if (abs(difference.get_x()) == abs(difference.get_y())) 
        result = true;
    
    return result;
}

    Vec2 &Vec2::operator= (Vec2 &rhs)
    {
        this->x = rhs.get_x();
        this->y = rhs.get_y();
        return *this;
    }

    bool Vec2::operator< (const Vec2 &rhs) const
    {
        bool result = false;
        if (this->x < rhs.get_x())
            result = true;
        else if (this->x > rhs.get_x())
            result = false;
        else
        {
            result = this->y < rhs.get_y();
        }
        
        return result;
    }



Vec2 operator- (const Vec2 &lhs, const Vec2 &rhs)
{
    Vec2 result;
    result.set_x(lhs.get_x() - rhs.get_x());
    result.set_y(lhs.get_y() - rhs.get_y());
    return result;
}

bool operator== (const Vec2 &lhs, const Vec2 &rhs)
{
    return (lhs.get_x() == rhs.get_x() && lhs.get_y() == rhs.get_y());
}

std::ostream &operator<< (std::ostream &lhs, const Vec2 &rhs)
{
    lhs << "x: " << rhs.get_x() << "   y: " << rhs.get_y();
    return lhs;
}


