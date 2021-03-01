#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<std::string, int> ages{{"James", 10}, {"Inyoung", 20}, {"Kim", 30}};

    for(const auto& [name, age] : ages)
    {
        std::cout << name << " is " << age << " years old" << std::endl;
    }

    return 0;
}
