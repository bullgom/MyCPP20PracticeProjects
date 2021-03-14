#include <vector>
#include <iostream>
#include <tuple>
#include <math.h>
#include "Point.h"

template <typename T>
T Point2D<T>::distance() const
{
    return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2));
}

template <typename T>
T Point2D<T>::distance(const Point2D<T> &rhs) const
{
    return std::sqrt(std::pow(rhs.x_ - x_, 2) + std::pow(rhs.y_ - y_, 2));
}

template <typename T>
T Point2D<T>::dot(Point2D<T> &rhs) const
{
    return x_ * rhs.x_ + y_ * rhs.y_;
}

template <typename T>
T Point2D<T>::cross(Point2D<T> &rhs) const
{
    return x_ * rhs.y_ - y_ * rhs.x_;
}

template <typename T>
const Point2D<T> Point2D<T>::operator+(Point2D<T> &rhs) const
{
    return {x_ + rhs.x_, y_ + rhs.y_};
}

template <typename T>
const Point2D<T> Point2D<T>::operator-(Point2D<T> &rhs) const
{
    return {x_ - rhs.x_, y_ - rhs.y_};
}

template <typename T>
bool Point2D<T>::operator==(Point2D<T> &rhs) const
{
    return (x_ == rhs.x_) and (y_ == rhs.y_);
}

template <typename T>
bool Point2D<T>::operator!=(Point2D<T> &rhs) const
{
    return (x_ != rhs.x_) or (y_ != rhs.y_);
}

template <typename T>
Point2D<T> &Point2D<T>::operator=(const Point2D<T> &rhs)
{
    x_ = rhs.x_;
    y_ = rhs.y_;
    return *this;
}

template <typename T>
Point2D<T> &Point2D<T>::operator+=(const Point2D<T> &rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}

template <typename T>
Point2D<T> &Point2D<T>::operator-=(const Point2D<T> &rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Point2D<T> &rhs)
{
    os << rhs.x_ << " " << rhs.y_;
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, Point2D<T> &rhs)
{
    is >> rhs.x_ >> rhs.y_;
    return is;
}

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

    return 0;
}
