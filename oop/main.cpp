#include "Point2d.h"

#include <iostream>
#include <cmath>

double distanceFrom(const Point2d& point1, const Point2d& point2)
{
  return std::sqrt(
    (point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) + (point1.m_y - point2.m_y) * (point1.m_y - point2.m_y)
  );
}

int main() {

    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();

    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}