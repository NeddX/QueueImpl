#ifndef QUEUE_H
#define QUEUE_H

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>

using usize   = std::size_t;
using ptrdiff = std::ptrdiff_t;
using intptr  = std::intptr_t;
using uintptr = std::uintptr_t;
using u8      = std::uint8_t;
using i8      = std::int8_t;
using u16     = std::uint16_t;
using i16     = std::int16_t;
using u32     = std::uint32_t;
using i32     = std::int32_t;
using u64     = std::uint64_t;
using i64     = std::int64_t;

namespace stl {
    template <typename T>
    class Queue
    {
    private:
        T*    m_Buffer       = nullptr;
        usize m_Size         = 0;
        usize m_Capacity     = 0;
        usize m_IndexPointer = 0;

    public:
        Queue() noexcept;
        Queue(const std::initializer_list<T> list) noexcept;
        Queue(const Queue<T>& other) noexcept;
        Queue(Queue<T>&& other) noexcept;
        ~Queue() noexcept;

    public:
        constexpr usize Size() const noexcept { return m_Size - m_IndexPointer; }
        constexpr bool  Empty() const noexcept { return Size() == 0; }

    private:
        void           Realloc(const usize newSize);
        constexpr void Drop() noexcept;

    public:
        void Push(const T& e);
        T    Pop();
        T&   Front();
        T&   Back();
        void Swap(Queue<T>& other) noexcept;

    public:
        inline Queue<T>& operator=(const Queue<T>& other);
        inline Queue<T>& operator=(Queue<T>&& other) noexcept;
        inline Queue<T>& operator=(const std::initializer_list<T> other) noexcept;

    public:
        friend std::ostream& operator<<(std::ostream& stream, const Queue<T>& other) noexcept
        {
            const auto size = other.Size();

            stream << "[ ";
            for (usize i = 0; i < size; ++i)
            {
                if (i + 1 == size)
                    stream << other.m_Buffer[other.m_IndexPointer + i];
                else
                    stream << other.m_Buffer[other.m_IndexPointer + i] << ", ";
            }
            stream << " ]";
            return stream;
        }
    };
} // namespace stl

// FIXME: Uncomment
#include "Queue.hpp"
#endif // QUEUE_H
