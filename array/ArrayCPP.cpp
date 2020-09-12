#include <iostream>

using namespace std;

template <class T>

class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new T[sz];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Insert(int ind, T x);
    T Delete(int ind);
};

template <class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

template <class T>
void Array<T>::Insert(int ind, T x)
{
    if (ind >= 0 && ind <= length)
    {
        for (int i = length - 1; i >= ind; i--)
            A[i + 1] = A[i];
        A[ind] = x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int ind)
{
    int x = -1;
    if (ind >= 0 && ind < length)
    {
        x = A[ind];
        for (int i = ind; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

int main(int argc, const char *argv[])
{
    Array<float> arr(10);
    arr.Insert(0, 5.1);
    arr.Insert(1, 6.0);

    arr.Insert(2, 9.5);
    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();

    return 0;
}