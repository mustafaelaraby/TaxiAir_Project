#pragma once

#include <iostream>
#include <stdexcept>
#include <functional>


template<typename T, typename Compare = std::less<T>>
class Priority_Queue {
private:
    T* m_data;      // Updated variable name
    size_t m_capacity;  // Updated variable name
    size_t m_size;  // Updated variable name
    Compare comp;  // No change needed for comp

    void heapifyUp(int);
    void heapifyDown(int);

public:
    Priority_Queue();
    explicit Priority_Queue(const Compare&);
    ~Priority_Queue();

    // Copy Constructor
    Priority_Queue(const Priority_Queue& other);

    // Move Constructor
    Priority_Queue(Priority_Queue&& other) noexcept;

    // Copy Assignment Operator
    Priority_Queue& operator=(const Priority_Queue& other);

    // Move Assignment Operator
    Priority_Queue& operator=(Priority_Queue&& other) noexcept;

    bool empty() const;
    size_t size() const;
    const T& at(size_t);
    void show();
    T& top();
    void pop();
    void push(const T&);
    void push(T&&);
    void popAt(size_t index);
};

template <typename T, typename Compare>
Priority_Queue<T, Compare>::Priority_Queue() : m_data(nullptr), m_capacity(0), m_size(0)
{}

template <typename T, typename Compare>
Priority_Queue<T, Compare>::Priority_Queue(const Compare& compare) : m_data(nullptr), m_capacity(0), m_size(0), comp(compare)
{}

template <typename T, typename Compare>
Priority_Queue<T, Compare>::~Priority_Queue()
{
    delete[] m_data;
}

template <typename T, typename Compare>
Priority_Queue<T, Compare>::Priority_Queue(const Priority_Queue& other)
    : m_capacity(other.m_capacity), m_size(other.m_size), comp(other.comp)
{
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

template <typename T, typename Compare>
Priority_Queue<T, Compare>::Priority_Queue(Priority_Queue&& other) noexcept
    : m_data(other.m_data), m_capacity(other.m_capacity), m_size(other.m_size), comp(std::move(other.comp))
{
    other.m_data = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
}

template <typename T, typename Compare>
Priority_Queue<T, Compare>& Priority_Queue<T, Compare>::operator=(const Priority_Queue& other)
{
    if (this != &other) {
        delete[] m_data;

        m_capacity = other.m_capacity;
        m_size = other.m_size;
        comp = other.comp;

        m_data = new T[m_capacity];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
    }
    return *this;
}

template <typename T, typename Compare>
Priority_Queue<T, Compare>& Priority_Queue<T, Compare>::operator=(Priority_Queue&& other) noexcept
{
    if (this != &other) {
        delete[] m_data;

        m_data = other.m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        comp = std::move(other.comp);

        other.m_data = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }
    return *this;
}

template <typename T, typename Compare>
void Priority_Queue<T, Compare>::heapifyUp(int index)
{
    if (index == 0)
        return;

    int parent = (index - 1) / 2;
    if (comp(m_data[index], m_data[parent])) {
        std::swap(m_data[parent], m_data[index]);
        heapifyUp(parent);
    }
}

template <typename T, typename Compare>
void Priority_Queue<T, Compare>::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < m_size && comp(m_data[leftChild], m_data[smallest]))
        smallest = leftChild;
    if (rightChild < m_size && comp(m_data[rightChild], m_data[smallest]))
        smallest = rightChild;

    if (smallest != index) {
        std::swap(m_data[index], m_data[smallest]);
        heapifyDown(smallest);
    }
}

template <typename T, typename Compare>
bool Priority_Queue<T, Compare>::empty() const
{
    return m_size == 0;
}

template <typename T, typename Compare>
size_t Priority_Queue<T, Compare>::size() const
{
    return m_size;
}

template <typename T, typename Compare>
const T& Priority_Queue<T, Compare>::at(size_t i)
{
    if (empty())
        throw std::runtime_error("Queue is empty");
    return m_data[i];
}



template <typename T, typename Compare>
T& Priority_Queue<T, Compare>::top()
{
    if (empty())
        throw std::runtime_error("Queue is empty");
    return m_data[0];
}

template <typename T, typename Compare>
void Priority_Queue<T, Compare>::pop()
{
    if (empty())
        throw std::runtime_error("Queue is empty");

    std::swap(m_data[0], m_data[m_size - 1]);
    m_size--;
    heapifyDown(0);
}

template <typename T, typename Compare>
void Priority_Queue<T, Compare>::push(const T& key)
{
    if (m_size == m_capacity) {
        // Resize the array if needed
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newHeap = new T[m_capacity];
        std::copy(m_data, m_data + m_size, newHeap);
        delete[] m_data;
        m_data = newHeap;
    }

    m_data[m_size++] = key;
    heapifyUp(m_size - 1);
}

template <typename T, typename Compare>
void Priority_Queue<T, Compare>::push(T&& key)
{
    if (m_size == m_capacity) {
        // Resize the array if needed
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newHeap = new T[m_capacity];
        std::copy(m_data, m_data + m_size, newHeap);
        delete[] m_data;
        m_data = newHeap;
    }

    m_data[m_size++] = std::move(key);
    heapifyUp(m_size - 1);
}

template <typename T, typename Compare>
void Priority_Queue<T, Compare>::popAt(size_t index)
{
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    // Swap the element at the specified index with the last element
    std::swap(m_data[index], m_data[m_size - 1]);

    // Decrease the size to effectively remove the element
    m_size--;

    // Perform heapify operations to maintain the heap property
    heapifyUp(index);
    heapifyDown(index);
}


template <typename T, typename Compare>
void Priority_Queue<T, Compare>::show()
{
    std::cout << "<";
    if (m_size > 0) {
        for (size_t i = 0; i < m_size - 1; ++i) {
            std::cout << m_data[i] << ", ";
        }
        std::cout << m_data[m_size - 1];
    }
    std::cout << ">" << std::endl;
}
