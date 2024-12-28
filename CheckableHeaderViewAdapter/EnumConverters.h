#ifndef ENUMCONVERTERS_H
#define ENUMCONVERTERS_H

#pragma once

#include <type_traits>


template <typename E>
constexpr typename std::underlying_type<E>::type operator+(E e)
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

namespace  {
template <typename T, typename = void>
constexpr bool HasColumnCount = false;
template <typename T>
constexpr bool HasColumnCount<T, std::void_t<decltype(T::COLUMNCOUNT)>> = true;

template <typename T, typename = void>
constexpr bool HasRowCount = false;
template <typename T>
constexpr bool HasRowCount<T, std::void_t<decltype(T::ROWCOUNT)>> = true;
}

template <typename TYPE>
TYPE enumCast(int value)
{
    if constexpr (HasColumnCount<TYPE>)
        Q_ASSERT(value >= 0 && value < +TYPE::COLUMNCOUNT);
    else if constexpr (HasRowCount<TYPE>)
        Q_ASSERT(value >= 0 && value < +TYPE::ROWCOUNT);
    else
        Q_ASSERT(value >= 0 && value < +TYPE::MAXCOUNT);
    return static_cast<TYPE>(value);
}

#endif // ENUMCONVERTERS_H
