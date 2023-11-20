#ifndef FTD_TOOLS_ENUMERATOR_H
#define FTD_TOOLS_ENUMERATOR_H

#include "Concepts.h"

namespace ftd::enum_operator {

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr std::underlying_type_t<Enum> to_underlying(Enum e) noexcept
{
    return static_cast<std::underlying_type_t<Enum>>(e);
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr bool enum_any(Enum e) noexcept
{
    return static_cast<bool>(e);
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr Enum operator|(Enum lhs, Enum rhs) noexcept
{
    return static_cast<Enum>(to_underlying(lhs) | to_underlying(rhs));
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr Enum operator&(Enum lhs, Enum rhs) noexcept
{
    return static_cast<Enum>(to_underlying(lhs) & to_underlying(rhs));
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr Enum operator^(Enum lhs, Enum rhs) noexcept
{
    return static_cast<Enum>(to_underlying(lhs) ^ to_underlying(rhs));
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr Enum operator~(Enum e) noexcept
{
    return static_cast<Enum>(~to_underlying(e));
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr Enum& operator|=(Enum& lhs, Enum rhs) noexcept
{
    return (Enum&)((std::underlying_type_t<Enum>&)(lhs) |= to_underlying(rhs));
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr Enum& operator&=(Enum& lhs, Enum rhs) noexcept
{
    return (Enum&)((std::underlying_type_t<Enum>&)(lhs) &= to_underlying(rhs));
}

template<typename Enum>
    requires is_scoped_enum_v<Enum>
constexpr Enum& operator^=(Enum& lhs, Enum rhs) noexcept
{
    return (Enum&)((std::underlying_type_t<Enum>&)(lhs) ^= to_underlying(rhs));
}

} // namespace ftd

#endif // FTD_TOOLS_ENUMERATOR_H
