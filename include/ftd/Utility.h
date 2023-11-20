#ifndef FTD_TOOLS_UTILITY_H
#define FTD_TOOLS_UTILITY_H

#include "Concepts.h"

namespace ftd {

// 多数时候，单例模式没有什么用，如果你用了，大概率是设计的不好
template<typename T, typename... Args>
    requires is_singletonizable<T, Args...>
T& make_singleton(Args&&... args)
{
    static T singleton { std::forward<Args>(args)... };

    return singleton;
}

} // namespace ftd

#endif // FTD_TOOLS_UTILITY_H
