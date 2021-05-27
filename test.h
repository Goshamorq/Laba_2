#pragma once

#include <chrono>
#include <utility>
#include <fstream>
#include <cassert>
#include <ctime>

using namespace std;
const int N = 10000;
#define loop(i, n) for(int i = 0; i < n; ++i)
#define assert_eq(l, r) assert(l==r)


void write(pair<double, double> time, const char *funcname)
{
    ofstream file("Compare.txt", std::ios_base::app);
    file << funcname << "\n";
    file << time.first << " " << time.second << " ";
    if (time.first < time.second)
        file << "\nArray better is " << round(time.second / time.first) << " times faster than a Linked_List\n";
    else
        file << "\nLinked_List better is " << round(time.first / time.second) << " times faster than a Array\n";
    file.close();
}

double *build(int n = N)
{
    srand(time(NULL));
    double *str = new double[n];
    loop(i, n)
    {
        double t = rand() % 10000;
        str[i] = t / (rand() % 100 + 1);
    }
    return str;
}

pair<double, double> test_concat()
{
    double *seq = build(N / 10);
    Vector<double> array(new ArraySequence<double>(seq, N / 10));
    Vector<double> list(new Linked_List_Sequence<double>(seq, N / 10));
    Vector<double> subList(new Linked_List_Sequence<double>(seq, N / 10));
    Vector<double> subArray(new ArraySequence<double>(seq, N / 10));
    auto begin_array = chrono::steady_clock::now();
    loop(i, N / 1000)
    {
        array.concat(subArray);
    }
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 1000)
    {
        list.concat(subList);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    Vector<double> subAr = *array.concat(subArray);
    Vector<double> subLs = *list.concat(subList);
    for (int i = 0; i < subAr.GetDimention() / 2; i++)
        assert(subAr[i] == array[i]);
    for (int i = subAr.GetDimention() / 2; i < subAr.GetDimention(); i++)
        assert(subAr[i] == subArray[i - subAr.GetDimention() / 2]);
    for (int i = 0; i < subLs.GetDimention() / 2; i++)
        assert(subLs[i] == list[i]);
    for (int i = subLs.GetDimention() / 2; i < subLs.GetDimention(); i++)
        assert(subLs[i] == subLs[i - subLs.GetDimention() / 2]);
    assert_eq(array.GetDimention(), list.GetDimention());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_insert()
{
    Vector<double> array(new ArraySequence<double>());
    Vector<double> list(new Linked_List_Sequence<double>());
    double j = 2;
    auto begin_array = chrono::steady_clock::now();
    double p = 2;
    loop(i, N / 10)
    {
        array.insert(p, array.GetDimention() / 2);
    }
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 10)
    {
        list.insert(p, list.GetDimention() / 2);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    for (int i = 0; i < array.GetDimention(); i++)
        assert(array[i] == p);
    for (int i = 0; i < list.GetDimention(); i++)
        assert(list[i] == p);
    assert_eq(array.GetDimention(), list.GetDimention());

    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_prepend()
{
    Vector<double> array(new ArraySequence<double>());
    Vector<double> list(new Linked_List_Sequence<double>());
    auto begin_array = chrono::steady_clock::now();
    double p = 2;
    loop(i, N / 2)
    {
        array.prepend(p);
    }
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 2)
    {
        list.prepend(p);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    for (int i = 0; i < array.GetDimention(); i++)
        assert(array[i] == p);
    for (int i = 0; i < list.GetDimention(); i++)
        assert(list[i] == p);
    assert_eq(array.GetDimention(), list.GetDimention());

    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_append()
{
    Vector<double> array(new ArraySequence<double>());
    Vector<double> list(new Linked_List_Sequence<double>());
    auto begin_array = chrono::steady_clock::now();
    double j = 2;
    double p = 2;
    loop(i, N / 10)
    {
        array.append(p);
    }
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 10)
    {
        list.append(p);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    for (int i = 0; i < array.GetDimention(); i++)
        assert(array[i] == p);
    for (int i = 0; i < list.GetDimention(); i++)
        assert(list[i] == p);
    assert_eq(array.GetDimention(), list.GetDimention());

    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_GetSubSeq()
{
    double *seq = build(N / 2);
    ArraySequence<double> array(seq, N / 2);
    Linked_List_Sequence<double> list(seq, N / 2);
    auto begin_array = chrono::steady_clock::now();
    loop(i, N / 100)
    {
        array.GetSubSeq(N / 8, 3 * N / 8);
    }

    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.GetDimention() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 100)
    {
        list.GetSubSeq(N / 8, 3 * N / 8);
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.GetDimention() << "\n" << list;
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    Sequence<double> *subArray = array.GetSubSeq(N / 8, 3 * N / 8);
    Sequence<double> *subList = list.GetSubSeq(N / 8, 3 * N / 8);
    for (int i = 0; i < (*subArray).getLength(); i++)
        assert((*subArray)[i] == array[i + N / 8]);
    for (int i = 0; i < (*subList).getLength(); i++)
        assert((*subList)[i] == list[i + N / 8]);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert(array.getLength() == list.getLength());

    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_get()
{
    double *seq = build();
    Vector<double> array(new ArraySequence<double>(seq, N));
    Vector<double> list(new Linked_List_Sequence<double>(seq, N));
    auto begin_array = chrono::steady_clock::now();
    loop(i, N)
    {
        array[i];
    }
    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.GetDimention() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N)
    {
        list[i];
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.GetDimention() << "\n" << list;
    auto elapsed_mcs_list = 10 * chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert_eq(array.GetDimention(), list.GetDimention());

    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}