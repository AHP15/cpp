#include "Point2d.h"

#include <iostream>

Point2d::Point2d(double x, double y)
  : m_x { x }, m_y { y }
{}

void Point2d::print() const
{
  std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}