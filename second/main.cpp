#include <iostream>
#include "Point2D.cpp"
#include "Polygon2D.cpp"

int main()
{
    Point2D p1{7.0, 6.0};
    Point2D p2{1.0, 3.0};
    Point2D p3{-10.0, 100.0};
    Point2D p4 = p3 - p1;
    std::cout << p3.x() << " " << p3.y() << std::endl;
    std::cout << p1.distance(p3 - p1) << std::endl;
    p3 -= p2;
    std::cout << p3.x() << " " << p3.y() << std::endl;
    std::cout << p1.distance(p3 - p1) << std::endl;
    std::cout << (p1 == p3) << std::endl;
    std::cout << (p1 == p1) << std::endl;
    std::cout << (p1 != p3) << std::endl;
    std::cout << (p1 != p1) << std::endl;

    std::vector<Point2D<double>> points{{-2., 0.}, {0., 2.}, {2., 0.}};

    Polygon2D p{points};

    return 0;
}
