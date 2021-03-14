#pragma once
#include <iostream>

template <typename T>
class Point2D
{
private:
    T x_;
    T y_;

public:
    Point2D(T x, T y) : x_{x}, y_{y} {};

    T x() const { return x_; };
    T y() const { return y_; };
    T distance() const;
    T distance(const Point2D<T> &rhs) const;

    T dot(Point2D<T> &rhs) const;
    T cross(Point2D<T> &rhs) const;

    const Point2D<T> operator+(Point2D<T> &rhs) const;
    const Point2D<T> operator-(Point2D<T> &rhs) const;
    bool operator==(Point2D<T> &rhs) const;
    bool operator!=(Point2D<T> &rhs) const;

    Point2D<T> &operator=(const Point2D<T> &rhs);

    Point2D<T> &operator+=(const Point2D<T> &rhs);
    Point2D<T> &operator-=(const Point2D<T> &rhs);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Point2D<U> &rhs);
    template <typename U>
    friend std::istream &operator>>(std::istream &is, Point2D<U> &rhs);
};
