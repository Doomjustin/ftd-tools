#ifndef FTD_TOOLS_NUMERIC_H
#define FTD_TOOLS_NUMERIC_H

#include <cstddef>
#include <type_traits>

namespace ftd {

// >= c++14，易读且高效
// 缺点：在特定场景下，可能不会在编译期执行计算，比如p不能在编译期确定时
constexpr bool is_prime(unsigned p)
{
    for (unsigned d = 2; d <= p / 2; ++d)
        if (p % d == 0)
            return false;

    return true;
}

template<typename T>
struct type_size {
    static constexpr std::size_t value = sizeof(T);
};

template<typename T1, typename T2>
struct plus_result {
    using type = decltype(std::declval<T1>() + std::declval<T2>());
};

template<typename T1, typename T2>
using plus_result_t = typename plus_result<T1, T2>::type;

} // namespace ftd

#endif // FTD_TOOLS_NUMERIC_H
