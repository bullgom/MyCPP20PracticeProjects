#include <iostream>
#include <memory>

struct Point
{
    int x;
    int y;
};

Point &doesNothing(Point &p)
{
    return p;
}

Point *doesNothing(Point *p)
{
    return p;
}

std::shared_ptr<Point> doesNothing(std::shared_ptr<Point> p)
{
    return p;
}

int main()
{
    Point original{.x = 10, .y = 20};

    Point reference = doesNothing(original);
    reference.x = 100;

    Point *pointer = new Point{.x = 10, .y = 20};
    Point *returnedPointer = doesNothing(pointer);
    returnedPointer->x = 100;

    auto smart_p = std::make_shared<Point>();
    auto returned_smart_p = doesNothing(smart_p);
    returned_smart_p->x = 100;

    std::cout << original.x << " " << original.y << std::endl;
    std::cout << reference.x << " " << reference.y << std::endl;

    std::cout << pointer->x << " " << pointer->y << std::endl;
    std::cout << returnedPointer->x << " " << returnedPointer->y << std::endl;

    std::cout << smart_p->x << " " << smart_p->y << std::endl;
    std::cout << returned_smart_p->x << " " << returned_smart_p->y << std::endl;

    return 0;
}
