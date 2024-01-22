#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
private:
    T* m_data;
    size_t m_capacity;
    size_t m_size;

public:
    // Constructors and Destructor
    Array();
    explicit Array(size_t initialCapacity);
    ~Array();

    // Copy Constructor
    Array(const Array& other);

    // Move Constructor
    Array(Array&& other) noexcept;

    // Copy Assignment Operator
    Array& operator=(const Array& other);

    // Move Assignment Operator
    Array& operator=(Array&& other) noexcept;

    // Element Access
    T& at(size_t index);
    const T& at(size_t index) const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Capacity
    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    // Modifiers
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
};

template <typename T>
Array<T>::Array() : m_data(nullptr), m_capacity(0), m_size(0)
{}

template <typename T>
Array<T>::Array(size_t initialCapacity) : m_data(new T[initialCapacity]), m_capacity(initialCapacity), m_size(0)
{}

template <typename T>
Array<T>::~Array()
{
    delete[] m_data;
}

template <typename T>
Array<T>::Array(const Array& other) : m_data(new T[other.m_capacity]), m_capacity(other.m_capacity), m_size(other.m_size)
{
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

template <typename T>
Array<T>::Array(Array&& other) noexcept : m_data(other.m_data), m_capacity(other.m_capacity), m_size(other.m_size)
{
    other.m_data = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other) {
        delete[] m_data;

        m_data = new T[other.m_capacity];
        m_capacity = other.m_capacity;
        m_size = other.m_size;

        std::copy(other.m_data, other.m_data + other.m_size, m_data);
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept
{
    if (this != &other) {
        delete[] m_data;

        m_data = other.m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }
    return *this;
}

template <typename T>
T& Array<T>::at(size_t index)
{
    if (index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

template <typename T>
const T& Array<T>::at(size_t index) const
{
    if (index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    return m_data[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return m_size;
}

template <typename T>
size_t Array<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
bool Array<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void Array<T>::push_back(const T& value)
{
    if (m_size == m_capacity) {
        // Resize the array if needed
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newData = new T[m_capacity];
        std::copy(m_data, m_data + m_size, newData);
        delete[] m_data;
        m_data = newData;
    }

    m_data[m_size++] = value;
}

template <typename T>
void Array<T>::push_back(T&& value)
{
    if (m_size == m_capacity) {
        // Resize the array if needed
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newData = new T[m_capacity];
        std::copy(m_data, m_data + m_size, newData);
        delete[] m_data;
        m_data = newData;
    }

    m_data[m_size++] = std::move(value);
}

template <typename T>
void Array<T>::pop_back()
{
    if (m_size > 0) {
        m_size--;
    }
    else {
        throw std::underflow_error("pop_back() called on an empty array");
    }
}
