#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdexcept>

using namespace std;

template<class T>
class Dynamic_array
{
private:
    int m_size;
    int Capacity;
    T *str;
public:
    Dynamic_array()
    {
        m_size = 0;
        Capacity = 0;
        str = nullptr;
    }

    ///копирование
    Dynamic_array(const Dynamic_array<T> &array)
    {
        m_size = array.size();
        Capacity = array.m_size;
        str = new T[array.size()];
        memcpy(str, array.str, array.size() * sizeof(T));
    }

    /// фул массив
    Dynamic_array(T *data, int count) : m_size(count)
    {
        if (count < 0)
            throw bad_alloc();
        Capacity = m_size;
        str = new T[count];
        memcpy(str, data, count * sizeof(T));
    }

    ///Размер в массив
    explicit Dynamic_array(int size)
    {
        if (size < 0)
            throw bad_alloc();//"Constructor Dynamic_array error,size<0"
        m_size = size;
        Capacity = size;
        str = new T[size];
        memset(str, 0, size);
    }

    /// Деструктор
    ~Dynamic_array<T>()
    {
        delete[] str;
        str = nullptr;
    }

    /// получение размера
    [[nodiscard]] int size() const
    {
        return m_size;
    }

    ///меняем размер
    void resize(int size)
    {
        if (size < 0)
            throw bad_array_new_length();
        if (size > Capacity)
        {
            Capacity = size * 2;
            T *new_data = new T[Capacity];
            memcpy(new_data, str, sizeof(T) * m_size);
            delete[] str;
            str = new_data;
            m_size = size;
        } else
            m_size = size;
    }

    /// вставка элемента в конец
    void append(T &item)
    {
        resize(m_size + 1);
        str[m_size - 1] = item;
    }

    /// вставка элемента в начало
    void prepend(T &item)
    {
        resize(m_size + 1);
        for (int j = m_size-1; j > 0; j--)
            str[j] = str[j - 1];
        str[0] = item;
    }

    /// вставка элемента по индексу
    void insert(T &item, int i)
    {
        if (i < 0 || i > m_size)
            throw out_of_range("Index out of range in function insert");
        if (i == 0)
        {
            prepend(item);
            return;
        }
        resize(m_size + 1);
        for (int j = m_size - 1; j > i; j--)
            str[j] = str[j - 1];
        str[i] = item;
    }

    T getFirst() const
    {
        return get(0);
    }

    T getLast() const
    {
        return get(m_size - 1);
    }

    T &get(int i) const
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range in function get");
        return str[i];
    }

    void set(int index, const T &item)
    {
        if (index < 0 || index >= m_size)
            throw out_of_range("Index out of range in function set");
        str[index] = item;
    }

    /// получение значения
    T operator[](int i) const
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range in operator []");
        return str[i];
    }

    /// присвоение значения
    T &operator[](int i)
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range in operator &[]");
        return str[i];
    }

    bool operator==(const T &a)
    {
        if (a.size() != m_size)
            return false;
        for (int i = 0; i < m_size; i++)
            if (str[i] != a[i])
                return false;
        return true;
    }


    /// вывод массива на экран
    void print()
    {
        for (int i = 0; i < m_size; ++i)
            cout << str[i] << " ";
        cout << "\n";
    }
};