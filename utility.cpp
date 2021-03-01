#include <iostream>

namespace utility
{
    /*
     * 선수 
     * `&&`.def - r-value reference
     * usually declare a parameter of a function
     * only takes a r-value expression
     * 
     * ex)
     * void foo(int&& a){} // this function takes only int type rvalues
     * 
     * int b;
     * foo(b); // error, b is a lvalue
     * foo(5); // Fine
     * foo(b+3); // Fine
     * 
     * int&& c = b; // Error
     * int&& d = 5; // Fine
     */

    /*
     * 대충 https://minjang.github.io/2015/12/03/python-range-c++11/
     * 에서 글어왔다는 뜻
     * 
     * range
     * c++ 표준
     * for (for-range-declaration : for-range-initializer ) statement
     * -- becomes --
     * {
     *  auto && _range = for-range-initializer;
     *  for ( auto _begin = begin-expr,
     *             _end   = end-expr;
     *        _begin != _end;
     *        ++_begin){
     *      for-range-declaration = *_begin;
     *      statement;
     * }
     * 여기서 begin-expr와 end-expr은 다음처럼 정의된다
     *  1. 
     *  for-range-initializer가 배열일 때,
     *  begin-expr = _range
     *  end-expr   = _range + _bound
     *  _bound 는 배열의 원소 개수
     * 
     *  2.
     *  [출처에선 begin 또는 end의 이름 멤버가 있다면 이라는데, 둘 다 있어야 되지 않을까?]
     *  for-range-initializer가 클래스이고, begin과 end 이름의 멤버가 있다면
     *  각각 _range.begin()과 _range_end()가 된다
     * 
     *  3.
     *  그 외라면 각각 begin(_range)와 end(_range)가 되는 적절한 함수를 찾는다
     * 
     * 1. loop의 시작과 끝을 각각 begin과 end를 통해 얻을 수 있고
     * 2. 전위 증가 [++i와 같이 변수 앞 증가]가 가능하며
     * 3. 시작과 끝을 비교하는데 사용하는 `!=` 연산자,
     * 4. loop내에서 값을 사용할 수 있도록 iterator의 *연산자 제공
     */

    template <typename T>
    class range_iterator;

    template <typename T>
    class range_impl
    {
        const T start_;
        const T stop_;
        const T step_;

    public:
        range_impl(T start, T stop, T step) : start_{start}, stop_{stop}, step_{step} {};
        range_impl(T start, T stop) : start_{start}, stop_{stop}, step_{1} {};
        range_impl(T stop) : start_{0}, stop_{stop}, step_{1} {};

        range_iterator<T> begin() const
        {
            return range_iterator<T>{start_, step_};
        }

        range_iterator<T> end() const
        {
            return range_iterator<T>{stop_, step_};
        }
    };

    template <typename T>
    class range_iterator
    {
        T current_;
        const T step_;

    public:
        range_iterator(T init, T step) : current_{init}, step_{step} {};

        range_iterator &operator++()
        {
            current_ += step_;
            return *this;
        }

        bool operator!=(const range_iterator<T> &rhs) const
        {
            return current_ != rhs.current_;
        }

        T operator*() const
        {
            return current_;
        }
    };

    template <typename T>
    range_impl<T> range(const T start, const T stop, const T step)
    {
        return range_impl<T>(start, stop, step);
    }

    template <typename T>
    range_impl<T> range(const T start, const T stop)
    {
        return range_impl<T>(start, stop);
    }

    template <typename T>
    range_impl<T> range(const T stop)
    {
        return range_impl<T>(stop);
    }
}; // namespace utility

int main()
{
    for (int i : utility::range(0, 10, 2))
    {
        std::cout << i << std::endl;
    }
}
