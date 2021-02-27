#include <iostream>
#include <string>

/*
 * Reference: docs.microsoft
 * A constant value is one that doesn't change
 * [상수 값이란, 변하지 않는 값을 말한다]
 * 
 * 
 */

/*
 * C++ provides two keywords to enable you to express the intent that an
 * object is not intended to be modified, and to enforce that intent
 * [cpp는 객체가 변경되지 않도록 의도됐다는 것을 표현하고 강제하기 위해서 
 * 두 개의 keyword를 제공한다]
 */

int main()
{
    /*
     * Constant Expression - Expressions that evaluate to a constant
     * [상수 표현 - 상수 값으로 결정나는 표현들]
     * Operands that are legal in constants expressions are
     * [상수 표현으로 인정되는 피연산자들은 다음이 있다]
     */

    // Literals
    int a = 100;                     // OK.integer literal
    std::string s = "stringLiteral"; // OK. text within double quotes are literal
    double d = 1.123;                // OK. double literal

    // Enumberation constants
    enum class Animal
    {
        Bird,
        Monkey,
        Tiger
    };
    Animal b = Animal::Bird; // OK. Enum is constant expression

    // Values declared as const that are initialized with constant expressions
    const int ci1 = 100; 
    const double ci2 = 100; // Can declare a value const with `const`

    // Size of expression
    int soci1 = sizeof(ci1);

    /*
     * C++ requires constant expressions for declarations of:
     * [다음 선언들을 위해선 상수 표현이 필요하다]
     */

    // 1. Array bounds
    // type variableName[array bound]
    int n[10]; // OK.
    int nn[ci1];
    
}
