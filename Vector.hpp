#pragma once

#include "Linked_List_Sequence.hpp"
#include "Dynamic_Array_Sequence.hpp"
#include <complex>
#include <math.h>
#include <iomanip>

using namespace std;

template<class T>
class Vector
{
private:
    Sequence<T> *vec;
public:

    explicit Vector(Sequence<T> *sequence) : vec(sequence)
    {};

    ~Vector()
    {
        clear();
    }

    Vector()
    {
        vec = nullptr;
    }

    explicit Vector(int count)
    {
        vec = new ArraySequence<T>(count);
    }


    Vector(T *items, int count)
    {
        vec = new ArraySequence<T>(items, count);
    }

//    Vector(const Vector<T> &copy)
//    {
//        vec = new ArraySequence<T>(*(copy.vec));
//    }

    T Get(int index) const
    {
        return vec->get(index);
    }

    void Set(int index, const T &items)
    {
        vec->set(index, items);
    }

    Vector<T> *sum(const Vector<T> &vec)
    {
        if (vec.GetDimention() != GetDimention())
            throw "Wrong size of vector";
        Vector<T> *res = new Vector(GetDimention());
        for (int i = 0; i < GetDimention(); i++)
        {
            res->Set(i, Get(i) + vec.Get(i));
        }
        return res;
    }

    Vector<T> *scalar(const T &num)
    {
        Vector<T> *res = new Vector(GetDimention());
        for (int i = 0; i < GetDimention(); i++)
        {
            res->Set(i, Get(i) * num);
        }
        return res;
    }

    complex<double> dot(const Vector<T> &a)
    {
        complex<double> num = 0;
        if (a.GetDimention() == GetDimention())
        {
            for (int i = 0; i < GetDimention(); i++)
            {
                num += Get(i) * conj(a.Get(i));
            }
        }
        return num;
    }

    double norm()
    {
        return sqrt(real(dot(*this)));
    }

    [[nodiscard]]int GetDimention() const
    {
        return vec->getLength();
    }

    void clear()
    {
        delete vec;
    }

    void print()
    {
        if (vec->getLength() == 0)
        {
            cout << "Length is zero";
            return;
        }
        cout << "{";
        int i = 0;
        for (i; i < vec->getLength() - 1; i++)
        {
            cout << vec->get(i) << "; ";
        }
        cout << vec->get(i) << "}" << endl;
    }

    //===============================//
    T operator[](int i) const
    {
        return (*vec)[i];
    }

    /// присвоение значения
    T &operator[](int i)
    {
        return (*vec)[i];
    }

    Vector<T> *concat(Vector<T> &seconvec)
    {
        return new Vector<T>((vec->concat(seconvec.vec)));
    }

    void insert(T &item, int index) const
    {
        vec->insert(item, index);
    }

    void prepend(T &item)
    {
        vec->prepend(item);
    }

    void append(T &item)
    {
        vec->append(item);
    }

    Vector<T> *GetSubSeq(int begin, int end) const
    {
        return new Vector<T>((vec->substr(begin, end)));
    }

    Vector<T> &operator=(const Vector<T> &vecc)
    {
        vec->resize(vecc.GetDimention());
        for (int i = 0; i < GetDimention(); i++)
            (*vec)[i] = vecc[i];
        return *this;
    }


//
//    istream &operator>>(istream &in)
//    {
//        T q;
//        for (int i = 0; i < vec->getLength(); i++)
//        {
//            in >> q;
//            vec->set(i, q);
//        }
//        return in;
//    }


};

