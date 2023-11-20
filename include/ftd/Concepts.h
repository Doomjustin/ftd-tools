#ifndef FTD_TOOLS_TYPETRAITS_H
#define FTD_TOOLS_TYPETRAITS_H

#include <concepts>
#include <type_traits>

namespace ftd {

template<typename E>
struct is_scoped_enum: std::bool_constant<requires
    {
        requires std::is_enum_v<E>;
        requires !std::is_convertible_v<E, std::underlying_type_t<E>>;
    }>
{};

template< class T >
inline constexpr bool is_scoped_enum_v = is_scoped_enum<T>::value;


template<class T>
concept is_copyable = std::copy_constructible<T> &&
                      std::assignable_from<T&, T&> &&
                      std::assignable_from<T&, const T&> &&
                      std::assignable_from<T&, const T>;

template<typename T, typename... Args>
concept is_singletonizable = std::constructible_from<T, Args...> &&
                             std::movable<T> &&
                             !is_copyable<T>;

} // namespace ftd

#endif // FTD_TOOLS_TYPETRAITS_H
