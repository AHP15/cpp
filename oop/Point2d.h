#ifndef POINT2D_H
#define POINT2D_H

class Point2d
{
private:
  double m_x {};
  double m_y {};
public:
  Point2d(double x = 0.0, double y = 0.0);
  void print() const;
  friend double distanceFrom(const Point2d&, const Point2d&);
};
#endif