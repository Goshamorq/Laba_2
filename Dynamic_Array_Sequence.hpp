#pragma once

#include "dynamic_array.hpp"
#include "Sequence.h"


template<class T>
class ArraySequence : public Sequence<T>
{
private:
    Dynamic_array<T> data;
public:
    /// Копирование элементов из переданного массива
    ArraySequence(T *items, int count) : data(items, count)
    {}

    /// Создание пустого массива
    ArraySequence() : data()
    {};

    explicit ArraySequence(int size) : data(size)
    {};

    /// Копирующий конструктор
    explicit ArraySequence(const Dynamic_array<T> &array) : data(array)
    {};

    [[maybe_unused]]void resize(int size)
    {
        data.resize(size);
    }

    T getFirst() const override
    {
        return data.getFirst();
    }

    T getLast() const override
    {
        return data.getLast();
    }

    T get(int index) const override
    {
        return data.get(index);
    }

    T operator[](int i) const override
    {
        return data.get(i);
    }

    T &operator[](int i) override
    {
        return data.get(i);
    }

    [[nodiscard]]int getLength() const override
    {
        return data.size();
    }

    Sequence<T> *GetSubSeq(int begin, int end) const override
    {
        if (begin < 0 || end < 0 || begin > end)
        {
            if (begin > end)
                throw invalid_argument("In function substring begin < end");
            else
                throw out_of_range("In function substring begin or end < 0");
        }
        if (end > data.size())
            throw out_of_range("In function substring end>size");
        auto *subArray = new ArraySequence<T>(end - begin + 1);
        for (int i = begin; i < end + 1; i++)
        {
            (*subArray)[i - begin] = data[i];
        }
        return subArray;
    }

    void set(int index, const T &item)
    {
        data.set(index, item);
    }

    void print() override
    {
        data.print();
    }

    void prepend(T &item) override
    {
        data.prepend(item);
    }

    void append(T &item) override
    {
        data.append(item);
    }

    void insert(T &item, int index) override
    {
        data.insert(item, index);
    }

    ArraySequence<T> *concat(Sequence<T> *secondArray) const override
    {
        ArraySequence<T> *res = new ArraySequence<T>(this->data);
        res->data.resize(getLength() + secondArray->getLength());
        for (int i = 0; i < secondArray->getLength(); i++)
        {
            (*res)[getLength() + i] = secondArray->get(i);
        }
        return res;
    }

    virtual ~ArraySequence() = default;
};