#include "main.hpp"

void test_constructors()
{
    cout << "Constructors" << endl;

    try
    {
        List<int> list0;
        List<int> list1(0, 10);
        List<int> list2(list1);
        List<double> list3(3, 0.1, 0.2, 0.4);

        cout << "<Default constructor>" << endl;
        cout << list0 << endl;

        cout << "<Constructor with parameters>" << endl;
        cout << list1 << endl;
        cout << list2 << endl;
        cout << list3 << endl;

        cout << "<Copying constructor>" << endl;
        list0 = list1;
        cout << list0 << endl;
    }
    catch (ErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

void test_addition()
{
    cout << "Elements addition" << endl;

    try
    {
        List<int> list0;
        List<int> list1;
        List<int> list2;

        cout << "<append(data)>" << endl;
        cout << list0 << endl;

        list0.append(11);
        cout << list0 << endl;

        list0.append(12);
        cout << list0 << endl;

        cout << "<insert(data, iter)>" << endl;
        cout << list1 << endl;

        ListIter<int> iter0(list1.begin());
        list1.insert(11, iter0);
        cout << list1 << endl;

        ListIter<int> iter1(list1.begin());
        list1.insert(12, iter1);
        cout << list1 << endl;

        ListIter<int> iter2(list1.end());
        list1.insert(13, iter2);
        cout << list1 << endl;
        list1.insert(14, iter2);
        cout << list1 << endl;

        cout << "<extend(list)>" << endl;
        cout << list2 << endl;

        list2.extend(list2);
        cout << list2 << endl;

        list2.extend(list0);
        cout << list2 << endl;

        list2.extend(list2);
        cout << list2 << endl;

        list2.extend(list1);
        cout << list2 << endl;
    }
    catch (ErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

void test_removal()
{
    cout << "Elements removal" << endl;

    try
    {
        List<int> list0(5, 1, 2, 3, 4, 5);

        cout << "<remove(iter)>" << endl;
        ListIter<int> iter0(list0.begin());
        cout << list0 << endl;

        list0.remove(iter0);
        cout << list0 << endl;

        ListIter<int> iter1(list0.begin());
        iter1++;
        ++iter1;
        list0.remove(iter1);
        cout << list0 << endl;

        cout << "<pop()>" << endl;
        cout << list0 << endl;

        list0.pop();
        cout << list0 << endl;

        list0.pop();
        cout << list0 << endl;

        list0.pop();
        cout << list0 << endl;

        cout << "<clear()>" << endl;
        cout << list0 << endl;

        list0.clear();
        cout << list0 << endl;
    }
    catch (ErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

void test_other()
{
    cout << "Other" << endl;

    try
    {
        List<int> list0(3, 1, 2, 3);
        List<int> list1(2, 1, 2);

        cout << "<size()>" << endl;
        cout << list0.size() << endl;
        cout << list1.size() << endl;

        cout << "<operators>" << endl;
        if (list0 != list1)
        {
            cout << "list2 not equal list7" << endl;
        }
        list0 += list1;
        cout << list0 << endl;
        list0 += 15;
        cout << list0 << endl;
    }
    catch (ErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

int main()
{
    cout << "Linear list testing" << endl;
    test_constructors();
    test_addition();
    test_removal();
    test_other();

    return 0;
}
