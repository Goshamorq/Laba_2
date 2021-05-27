#pragma once

#include "linked_list.hpp"
#include "Sequence.h"

template<class T>
class Linked_List_Sequence : public Sequence<T>
{
    List<T> data;

public:
    /// Копирование элементов из переданного массива
    Linked_List_Sequence(T *items, int count) : data(items, count)
    {}

    /// Создание пустого связного списка
    Linked_List_Sequence() : data()
    {};

    /// Копирующий конструктор
    explicit Linked_List_Sequence(const List<T> &list) : data(new List<T>(list))
    {};

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
        return data[i];
    }

    T &operator[](int i) override
    {
        return data[i];
    }

    [[nodiscard]]int getLength() const override
    {
        return data.getLength();
    }

    void append(T &item) override
    {
        data.append(item);
    }

    void prepend(T &item) override
    {
        data.prepend(item);
    }

    void insert(T &item, int index) override
    {
        data.insert(item, index);
    }

    ///конкатинация строк
    Sequence<T> *concat(Sequence<T> *secondList) const override
    {
        auto *res = new Linked_List_Sequence<T>(*this);
        for (int i = 0; i < secondList->getLength(); i++)
        {
            res->append((*secondList)[i]);
        }
        return res;
    }

    void set(int index, const T &item) override
    {
        if (index < 0 || index >= getLength())
            throw out_of_range("Index out of range in function set");
        int j = 0;
        for (Node<T> *node = data.getHead(); node != nullptr; node = node->pNext)
        {
            if (j == index)
            {
                node->data = item;
                return;
            }
            j++;
        }

    }

    ///получить кусок списка
    Sequence<T> *GetSubSeq(int begin, int end) const override
    {
        if (begin < 0 || end < 0 || begin > end)
        {
            if (begin > end)
                throw invalid_argument("In function substring begin < end");
            else
                throw out_of_range("In function substring begin or end < 0");
        }
        Node<T> *now = data.getHead();
        for (int i = 0; i < begin; i++)
            now = now->pNext;
        auto *subList = new Linked_List_Sequence<T>();
        for (int i = begin; i < end + 1; i++)
        {
            subList->append(now->data);
            now = now->pNext;
        }
        return subList;
    }

    void print() override
    {
        data.print();
    }


    virtual ~Linked_List_Sequence() = default;
};