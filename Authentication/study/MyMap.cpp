#include <map>
#include <iostream>
#include <string>

/*
 * cppreference.com 왈
 * std::map은 sorted associative container 즉,
 * 1. sorted 정렬 되어 있다.
 *       key에 의해 정렬되어 있다
 * 2. associative container
 *       출처: https://stackoverflow.com/questions/20097551/what-is-an-associative-container
 *       Def. 인덱스가 0으로 시작하지 않는 container의 종류
 * 
 * associative container 속도 비교
 * 출처: https://www.modernescpp.com/index.php/associative-containers-a-simple-performance-comparison
 * associative container     cl.exe  g++     cl.exe/Ox   g++ -03
 * std::map                  1.81    1.629   0.988       1.300
 * std::unordered_map        0.534   0.294   0.087       0.087 <- 훨씬 빠름
 */
int main()
{
    
    std::map<std::string, int> ages{{"James", 10}, {"Inyoung", 20}, {"Kim", 30}};

    for(const auto& [name, age] : ages)
        std::cout << name << " is " << age << " years old" << std::endl;
    


    return 0;
}
