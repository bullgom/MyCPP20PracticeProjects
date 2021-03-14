#pragma once
#include <iostream>
#include <vector>
#include "Polygon2D.h"
#include "Point2D.cpp"

template <typename T>
Polygon2D<T>::Polygon2D(std::vector<Point2D<T>> &points)
{
    if (points.size() < 3)
        throw std::invalid_argument(
            "Need atleast 3 points to create a Polygon2D. Got" + std::to_string(points.size()));
    points_ = points;
}
