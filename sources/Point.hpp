
#ifndef POINT_H
#define POINT_H  

// using namespace ariel;
namespace ariel
{
    
  class Point
  {
    public:
      Point(double x_axis, double y_axis);  // declare default constructor
      double distance(const Point& other) const;
      void print();
      static Point moveTowards(Point& orign, Point& destenation, double dist);
      double getX() const;
      double getY() const;
      void setX(double x_axis);
      void setY(double y_axis);
      void setPoint(Point other);

    private:
      double x_axis;
      double y_axis;
  };
}
#endif