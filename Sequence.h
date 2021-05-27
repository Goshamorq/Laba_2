#pragma once

template<typename T>
class Sequence
{
public:
    /// получение первого элемента
    virtual T getFirst() const = 0;

    /// получение последнего элемента
    virtual T getLast() const = 0;

    /// получение элемента по индексу
    virtual T get(int index) const = 0;

    /// установка значения по индексу
    virtual void set(int index, const T &item) = 0;

    /// получение значения
    virtual T operator[](int i) const = 0;

    /// присвоение значения
    virtual T &operator[](int i) = 0;

    /// получить длину строки
    [[nodiscard]]virtual int getLength() const = 0;

    /// вставка элемента в конец
    virtual void append(T &item) = 0;

    /// вставка элемента в начало
    virtual void prepend(T &item) = 0;

    /// вставка элемента по индексу
    virtual void insert(T &item, int index) = 0;

    /// получение substr с begin до end
    virtual Sequence<T> *GetSubSeq(int begin, int end) const = 0;

    /// Соединение двух строк
    virtual Sequence<T> *concat(Sequence<T> *second_str) const = 0;

    /// Вывод строки
    virtual void print() = 0;

    /// Деструктор
    virtual ~Sequence<T>() = default;

};