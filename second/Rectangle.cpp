template <typename T>
class Rectangle
{
private:
    T x_, y_, height_, width_;

public:
    Rectangle() : height_{0}, width_{0}, x_{0}, y_{0} {/*empty*/};
    Rectangle(T x, T y, T height, T width) : height_{height}, width_{width}, x_{x}, y_{y} {/*empty*/};
    ~Rectangle() = default;

    T height() const;
    T width() const;
    T area() const;

    bool operator!=(const Rectangle &rhs);
    bool operator==(const Rectangle &rhs);
    bool operator>(const Rectangle &rhs);
    bool operator<(const Rectangle &rhs);
};

template <typename T>
bool Rectangle<T>::operator!=(const Rectangle<T> &rhs)
{
    return (x_ != rhs.x_ or y_ != rhs.y_ or height_ != rhs.height_ or width_ != rhs.width_);
}

template <typename T>
bool Rectangle<T>::operator==(const Rectangle<T> &rhs)
{
    return (x_ != rhs.x_ and y_ != rhs.y_ and height_ != rhs.height_ and width_ != rhs.width_);
}

template <typename T>
bool Rectangle<T>::operator>(const Rectangle<T> &rhs)
{
    return area() > rhs.area();
}

template <typename T>
bool Rectangle<T>::operator<(const Rectangle<T> &rhs)
{
    return area() < rhs.area();
}

int main()
{
    Rectangle<int>();
    Rectangle(1, 2, 3, 4);
}
