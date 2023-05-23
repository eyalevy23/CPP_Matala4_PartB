#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;
namespace ariel
{
    Point::Point(double x_axis, double y_axis) : x_axis(x_axis), y_axis(y_axis)
    {
    }

    double Point::getX() const
    {
        return this->x_axis;
    }

    double Point::getY() const
    {
        return this->y_axis;
    }

    void Point::setX(double x)
    {
        x_axis = x;
    }

    void Point::setY(double y)
    {
        y_axis = y;
    }

    double Point::distance(const Point& other) const {
        double dx = other.x_axis - x_axis;
        double dy = other.y_axis - y_axis;
        return sqrt(dx * dx + dy * dy);
    }

    void Point::setPoint(Point other)
    {
        this->x_axis = other.x_axis;
        this->y_axis = other.y_axis;
    }


    void Point::print()
    {
        cout << "(" << this->x_axis << ", " << this->y_axis << ")" << endl;
    }

    Point Point::moveTowards(Point& orign, Point& destenation, double dist)
    {
        // double dx = destenation.x - orign.x;
        // double dy = destenation.y - orign.y;
        // double length = sqrt(dx * dx + dy * dy);
        // double x = orign.x + dx / length * distance;
        // double y = orign.y + dy / length * distance;
        // return Point(x, y);

        if(dist < 0)
        {
            throw "distance must be positive";    
        }
        else if(dist > orign.distance(destenation))
        {
            return Point(destenation.getX(), destenation.getY());
        }
        double dist_OrginToDest = orign.distance(destenation);
        double ratio = dist / dist_OrginToDest;
 
        double newX = (1 - ratio) * (orign.getX()) + (ratio * destenation.getX());
        double newY = (1 - ratio) * (orign.getY()) + (ratio * destenation.getY());
        return Point(newX, newY);
        
    }

}
