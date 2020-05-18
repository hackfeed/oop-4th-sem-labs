#include "main.hpp"

int main()
{
    cout << "Тестировние списка одностороннего доступа" << endl;

    try
    {
        cout << "\n\nКонстуркторы" << endl;

        List<int> list0;
        List<int> list1(0, 10);
        List<int> list2(list1);
        List<double> list3(3, 0.1, 0.2, 0.4);

        cout << "\n * Констурктор по умолчанию" << endl;
        cout << list0 << endl;

        cout << "\n * Констуркторы с параметрами" << endl;
        cout << list1 << endl;
        cout << list2 << endl;
        cout << list3 << endl;

        cout << "\n * Констурктор копирования" << endl;
        list0 = list1;
        cout << list0 << endl;

        cout << "\n\nДобавления элементов" << endl;

        List<int> list4;
        List<int> list5;
        List<int> list6;

        cout << "\n * append(data)" << endl;
        cout << list4 << endl;
        list4.append(11);
        cout << list4 << endl;
        list4.append(12);
        cout << list4 << endl;

        cout << "\n * insert(data, iter)" << endl;
        cout << list5 << endl;
        ListIter<int> iter0(list5.begin());
        list5.insert(11, iter0);
        cout << list5 << endl;
        ListIter<int> iter1(list5.begin());
        list5.insert(12, iter1);
        cout << list5 << endl;
        ListIter<int> iter2(list5.end());
        list5.insert(13, iter2);
        cout << list5 << endl;
        list5.insert(14, iter2);
        cout << list5 << endl;

        cout << "\n * extend(list)" << endl;
        cout << list6 << endl;
        list6.extend(list6);
        cout << list6 << endl;
        list6.extend(list4);
        cout << list6 << endl;
        list6.extend(list6);
        cout << list6 << endl;

        list6.extend(list5);
        List<int> list7(list6);

        cout << "\n\nУдаление элементов" << endl;

        cout << "\n * remove(iter)" << endl;
        ListIter<int> iter3(list7.begin());
        cout << list7 << endl;
        list7.remove(iter3);
        cout << list7 << endl;
        ListIter<int> iter4(list7.begin());
        iter4++;
        ++iter4;
        list7.remove(iter4);
        cout << list7 << endl;

        cout << "\n * pop()" << endl;
        list7.pop();
        cout << list7 << endl;
        list7.pop();
        cout << list7 << endl;
        list7.pop();
        cout << list7 << endl;

        cout << "\n * clear()" << endl;

        cout << "\n\nДругие методы" << endl;
        cout << list6.size() << endl;
        cout << list7.size() << endl;
        if (list6 != list7)
            cout << "list6 not equal list7" << endl;
        list7 += list6;
        cout << list7 << endl;
        list7 += 15;
        cout << list7 << endl;

        list7.clear();
        list7.pop();
    }
    catch (ErrorBase &error)
    {
        cout << error.what() << endl;
    }

    return 0;
}
