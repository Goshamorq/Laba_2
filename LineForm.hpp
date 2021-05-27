#pragma once

#include "Dynamic_Array_Sequence.hpp"
#include <complex>

template<class T>
class LineForm
{
private:
    ArraySequence<T> *form;
public:
    LineForm()
    {
        form = nullptr;
    }

    explicit LineForm(int n)
    {
        form = new ArraySequence<T>(n);
    }

    LineForm(T *items, int n)
    {
        form = new ArraySequence<T>(items, n);
    }

    LineForm(const LineForm<T> &copy)
    {
        form = new ArraySequence<T>(*copy.form);
    }

    T Get(int index) const
    {
        return form->get(index);
    }

    void Set(int index, const T &items)
    {
        form->set(index, items);
    }

//    LineForm<T> *SUM (const LineForm<T> &second)
//    {
//        int a, b;
//        if (getSize() > second.getSize())
//        {
//            a = getSize();
//            b = second.getSize();
//        } else
//        {
//            b = getSize();
//            a = second.getSize();
//        }
//        LineForm<T> *res = new LineForm(a);
//        int i = 0;
//        for (i; i < b; i++)
//        {
//            res->Set(i, Get(i) + second.Get(i));
//        }
//        if (getSize() > second.getSize())
//        {
//            for (i; i < a; i++)
//            {
//                res->Set(i, Get(i));
//            }
//        } else
//        {
//            for (i; i < a; i++)
//            {
//                res->Set(i, second.Get(i));
//            }
//        }
//        return res;
//    }

    [[nodiscard]]int getSize() const
    {
        return form->getLength();
    }

    void scalar(T a)
    {
        for (int i = 0; i < getSize(); i++)
        {
            Set(i, Get(i) * a);
        }
    }

    T calculate()
    {
        if (getSize() == 0)
        {
            cout << "Sum iz zero\n";
            return 0;
        }
        cout << "Enter the values of " << getSize() - 1 << " variable(s)" << endl;
        T sum = Get(0);
        T x;
        for (int i = 1; i < getSize(); i++)
        {
            cin >> x;
            sum += Get(i) * x;
        }
        return sum;
    }

    LineForm<T> operator+(const LineForm<T> &second);

    LineForm<T> operator-(const LineForm<T> &second);

    LineForm<T> operator<<(const ostream &out);

    LineForm<T> operator>>(const istream &in);

    LineForm<T> operator*(T a);

    void clear()
    {
        delete form;
    }

    void print()
    {
        if (form->getLength() == 0)
        {
            cout << "Length is zero";
            return;
        }
        int i = 0;
        cout << "(" << form->get(i) << ")";
        i++;
        for (i; i < form->getLength(); i++)
        {
            cout << " + " << "(" << form->get(i) << ")" << "X_" << i;
        }
        cout << endl;
    }

};

template<typename T>
LineForm<T> LineForm<T>::operator+(const LineForm<T> &second)
{
    int a, b;
    if (getSize() > second.getSize())
    {
        a = getSize();
        b = second.getSize();
    } else
    {
        b = getSize();
        a = second.getSize();
    }
    LineForm<T> *res = new LineForm(a);
    int i = 0;
    for (i; i < b; i++)
    {
        T hui = Get(i) + second.Get(i);
        res->Set(i, hui);
    }
    if (getSize() > second.getSize())
    {
        for (i; i < a; i++)
        {
            res->Set(i, Get(i));
        }
    } else
    {
        for (i; i < a; i++)
        {
            res->Set(i, second.Get(i));
        }
    }
    return *res;
}

template<class T>
LineForm<T> LineForm<T>::operator-(const LineForm<T> &second)
{
    int a, b;
    if (getSize() > second.getSize())
    {
        a = getSize();
        b = second.getSize();
    } else
    {
        b = getSize();
        a = second.getSize();
    }
    LineForm<T> *res = new LineForm(a);
    int i = 0;
    for (i; i < b; i++)
    {
        res->Set(i, Get(i) + second.Get(i) * T(-1));
    }
    if (getSize() > second.getSize())
    {
        for (i; i < a; i++)
        {
            res->Set(i, Get(i));
        }
    } else
    {
        for (i; i < a; i++)
        {
            res->Set(i, second.Get(i) * T(-1));
        }
    }
    return *res;
}

template<class T>
LineForm<T> LineForm<T>::operator<<(const ostream &out)
{
    for (int i = 0; i < getSize(); ++i)
    {
        out << Get(i) << " ";
    }
    return out;
}

template<class T>
LineForm<T> LineForm<T>::operator>>(const istream &in)
{
    T x;
    for (int i = 0; i < getSize(); i++)
    {
        in >> x;
        Set(i, x);
    }
    return in;
}

template<class T>
LineForm<T> LineForm<T>::operator*(const T a)
{
    LineForm<T> ans(*this);
    for (int i = 0; i < getSize(); i++)
    {
        ans.Set(i, Get(i) * a);
    }
    return ans;
}
