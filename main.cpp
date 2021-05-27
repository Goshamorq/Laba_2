#include "Vector.hpp"
#include "LineForm.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include "test.h"

#define CIN_FLUSH if (cin.peek()) cin.ignore()

const string Menu[] = {"1.Enter vector ", "2.Sum vector",
                       "3.Scalar ", "4.Dot", "5.Norm", "6.Enter line form",
                       "7.Sum", "8.Scalar", "9.Calculate", "10.Exit", "11.Test"};
const int numMenu = 11;

int getmenu()
{
    string error = "";
    int ch = 0;
    do
    {
        cout << error;
        error = "Wrong value. Try again!\n";
        for (int i = 0; i < numMenu; i++)
        {
            cout << Menu[i] << "\n";
        }
        cout << "Make your choice: \n";
        cin >> ch;
        while (getchar() != '\n')
        {}
    } while (ch < 1 || ch > numMenu);
    return ch;
}

template<typename T>
T *read(int size)
{
    T *res = new T[size];
    for (int i = 0; i < size; i++)
    {
        cin >> res[i];
    }
    return res;
}

complex<double> *readCom(int size)
{
    complex<double> *res = new complex<double>[size];
    for (int i = 0; i < size; i++)
    {
        double a, b;
        cin >> a >> b;
        res[i].real(a);
        res[i].imag(b);
    }
    return res;
}

int main()
{
    int turn = 1;
    int res = 0;
//    Vector<double> array(new ArraySequence<double>());
//    Vector<double> list(new Linked_List_Sequence<double>());
//    cout<<array.GetDimention()<<" "<<list.GetDimention()<<"\n";
    while (turn)
    {
        res = getmenu();
        switch (res)
        {
            case 1:///вводим вектор
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<double> vec1(read<double>(n), n);
                        vec1.print();
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector\n";
                        Vector<complex<double>> vec1(readCom(n), n);
                        vec1.print();
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }

            case 2:///суммируем векторы
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<double> vec1(read<double>(n), n);
                        cout << "Enter the second vector:\n";
                        Vector<double> vec2(read<double>(n), n);
                        Vector<double> *res = vec1.sum(vec2);
                        res->print();
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<complex<double>> vec1(readCom(n), n);
                        cout << "Enter the second vector:\n";
                        Vector<complex<double>> vec2(readCom(n), n);
                        Vector<complex<double>> *res = vec1.sum(vec2);
                        res->print();
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 3:///Умножаем на скаляр
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        double num;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<double> vec1(read<double>(n), n);
                        cout << "Multiply by:\n";
                        cin >> num;
                        vec1.scalar(num)->print();
                        break;
                    }
                    case 2:
                    {
                        int n;
                        double num;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<complex<double>> vec1(readCom(n), n);
                        cout << "Multiply by:\n";
                        cin >> num;
                        vec1.scalar(num)->print();
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 4:///
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<double> vec1(read<double>(n), n);
                        cout << "Enter the second vector:\n";
                        Vector<double> vec2(read<double>(n), n);
                        complex<double> res = vec1.dot(vec2);
                        cout << "Result :" << res << endl;
                        scanf("%*c");
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<complex<double>> vec1(readCom(n), n);
                        cout << "Enter the second vector:\n";
                        Vector<complex<double>> vec2(readCom(n), n);
                        complex<double> res = vec1.dot(vec2);
                        cout << "Result :" << res << endl;
                        scanf("%*c");
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 5:///Норма
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<double> vec1(read<double>(n), n);
                        double res = 0;
                        try
                        {
                            res = vec1.norm();
                        } catch (const char *s)
                        {
                            cerr << s << endl;
                            break;
                        }

                        cout << "Result:" << res << endl;
                        scanf("%*c");
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the vector:\n";
                        Vector<complex<double>> vec1(readCom(n), n);
                        double res = 0;
                        try
                        {
                            res = vec1.norm();
                        } catch (const char *s)
                        {
                            cerr << s << endl;
                            break;
                        }

                        cout << "Result:" << res << endl;
                        scanf("%*c");
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 6:///Вводим линейную форму
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<double> form1(read<double>(n), n);
                        form1.print();
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<complex<double>> form1(readCom(n), n);
                        form1.print();
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 7:///Сумма линейной
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        cout << "Enter dimension of first norm\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<double> form1(read<double>(n), n);
                        cout << "Enter dimension of second norm\n";
                        cin >> n;
                        cout << "Enter the norm coefficients for second form:\n";
                        LineForm<double> form2(read<double>(n), n);
                        LineForm<double> res = form1 + form2;
                        res.print();
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout << "Enter dimension of first norm\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<complex<double>> form1(readCom(n), n);
                        cout << "Enter dimension of second norm\n";
                        cin >> n;
                        cout << "Enter the norm coefficients for second form:\n";
                        LineForm<complex<double>> form2(readCom(n), n);
                        LineForm<complex<double>> res = form1 + form2;
                        res.print();
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 8:///На скаляр
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        double num;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<double> form1(read<double>(n), n);
                        cout << "Multiply by:\n";
                        cin >> num;
                        LineForm<double> res = form1 * num;
                        res.print();
                        break;
                    }
                    case 2:
                    {
                        int n;
                        double num;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<complex<double>> form1(readCom(n), n);
                        cout << "Multiply by:\n";
                        cin >> num;
                        LineForm<complex<double>> res = form1 * num;
                        res.print();
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 9:
            {
                cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                cin >> choose;
                switch (choose)
                {
                    case 1:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<double> form1(read<double>(n), n);
                        cout << form1.calculate() << endl;
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout << "Enter dimension\n";
                        cin >> n;
                        cout << "Enter the norm coefficients:\n";
                        LineForm<complex<double>> form1(readCom(n), n);
                        cout << form1.calculate() << endl;
                        break;
                    }
                    default:
                    {
                        cout << "Incorrect choose";
                        CIN_FLUSH;
                        break;
                    }
                }
                break;
            }
            case 10:///Выходим
            {
                std::cout << "Goodbye";
                turn = 0;
                CIN_FLUSH;
                break;
            }
            case 11: /// Экстравозможность теста
            {
                ofstream file("Compare.txt", ios_base::trunc);
                file << "Function name\ntime array time Linked_List\n";
                file.close();
                write(test_insert(), "Insert");
                write(test_prepend(), "Prepend");
                write(test_append(), "Append");
                write(test_GetSubSeq(), "GetSubSeq");
                write(test_get(), "Get");
                write(test_concat(), "Concat");
            }
        }
    }

    return 0;
}
