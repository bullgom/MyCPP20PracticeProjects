

/*
 * This file is used to study cpp that will be used in this sub-project
 */

/*
 * Struct
 * A struct is a `type`, consisting of a sequence of members whose storage
 * is allocated in an ordered sequence
 * (Opposed to `union`, which is a type consisting of a sequence of members
 *  whose storage overlaps)
 */

struct S
{
    int n;
    double d[]; // S.d is a flexible array member [What is flexible array member]
};

// 
struct S t1 = {0};

/*
 * Type for callables
 */

template <typename T>
struct func_traits : public func_traits<decltype(&T::operator())>
{
};
