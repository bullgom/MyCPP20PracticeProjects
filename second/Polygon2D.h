#pragma once
#include <iostream>
#include <vector>
#include "Point2D.h"

template <typename T>
class Polygon2D
{
private:
    std::vector<Point2D<T>> points_;

public:
    Polygon2D<T>(std::vector<Point2D<T>> &points);

};
