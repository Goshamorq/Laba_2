#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
    Node *pNext;
    T data;

    Node(T data = T(), Node *pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }

    Node(const Node &copyNode) : data(copyNode.data), pNext(copyNode.pNext ? new Node(*copyNode.pNext) : nullptr)
    {}
};

///Сам связный список
template<typename T>
class List
{
public:
    List();

    List(T *items, int size);

    List(const List<T> &list);

    ~List();

    void append(T data);

    void prepend(T data);

    void pop_front();

    Node<T> *getHead() const;

    List<T> *GetSubList(int begin, int end);

    void clear();

    T getFirst() const;

    T getLast() const;

    T &get(int index) const;

    void insert(T value, int index);

    int getLength() const
    { return Size; }

    T &operator[](const int index);

    T operator[](int index) const;

    void print()
    {
        for (Node<T> *node = head; node != nullptr; node = node->pNext)
        {
            cout << node->data << " ";
        }
        cout << "\n";
    }


private:

    int Size = 0;
    Node<T> *head = nullptr;
};

/// Конструктор по умолчанию
template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}


/// Деструктор
template<typename T>
List<T>::~List()
{
    clear();
}

///в конец
template<typename T>
void List<T>::append(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    } else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

/// В начало
template<typename T>
void List<T>::prepend(T data)
{
    head = new Node<T>(data, head);
    Size++;
}


template<typename T>
T &List<T>::operator[](const int index)
{
    if (index < 0 || index >= Size)
        throw out_of_range("Index out of range in function get");

    int counter = 0;
    Node<T> *current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        counter++;
        current = current->pNext;
    }

}

template<typename T>
///Удаляет 1й элемент
void List<T>::pop_front()
{
    if (head == nullptr)
        throw out_of_range("The list is empty");
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
///Удаляет весь список
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
///Вставляю элемент по индексу
void List<T>::insert(T value, int index)
{
    if (index < 0 || index > Size)
    {
        throw out_of_range("Index out of range in function get");
    }
    if (index == 0)
    {
        prepend(value);
    } else
    {
        Node<T> *prev = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            prev = prev->pNext;
        }
        prev->pNext = new Node<T>(value, prev->pNext);
        Size++;
    }

}

template<typename T>
T List<T>::getFirst() const
{
    if (Size == 0)
        throw out_of_range("The list is empty");
    else
        return head->data;
}

template<typename T>
T List<T>::getLast() const
{
    if (Size == 0)
        throw out_of_range("The list is empty");
    else
    {
        Node<T> *temp = this->head;
        while (temp->pNext != nullptr)
        {
            temp = temp->pNext;
        }
        return temp->data;
    }
}

template<typename T>
T &List<T>::get(int index) const
{
    if (Size == 0)
        throw out_of_range("The list is empty");
    int count = 0;
    Node<T> *temp = this->head;
    while (count != index)
    {
        temp = temp->pNext;
        count++;
    }
    return temp->data;
}

///конструктор копирования
template<typename T>
List<T>::List(const List<T> &list): Size(list.Size)
{
    int i = 0;
    Node<T> *temp = list.head;
    Node<T> *end = nullptr;
    while (temp)
    {
        Node<T> *n = new Node<T>;
        n->data = temp->data;

        if (!head)
        {
            head = n;
            end = head;
        } else
        {
            end->pNext = n;
            end = n;
        }

        temp = temp->pNext;
    }
    /*for (Node<T> *it = list.head; i < list.Size; i++, it->pNext)
    {
        auto *node = new Node<T>(it->data, it->pNext);
        if (head == nullptr)
            head = node;
    }*/

}

///создание списка
template<typename T>
List<T>::List(T *items, int size): Size(0)
{
    for (int i = 0; i < size; i++)
    {
        append(items[i]);
    }
}

template<typename T>
Node<T> *List<T>::getHead() const
{
    return head;
}

template<typename T>
T List<T>::operator[](int index) const
{
    return get(index);
}
