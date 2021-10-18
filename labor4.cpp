#include <iostream>
#include <memory>

using namespace std;

class MyVector
{
private:
    int* head;
    int length;
public:
    MyVector(int length)
    {
        if (length > 0) { length = abs(length); }
        this->length = length;
        head = new int[length];
        for (int i = 0; i < length; i++)
        {
            
            cout << "Введите число в строку матрицы: " << endl;
            cin >> head[i];
            
        }
    }
    MyVector()
    {
        length = -1;
        head = nullptr;
    }
    ~MyVector()
    {
        cout << "1";
        if (length != -1)
        {
            delete[] head;
        }
    }
    int operator[](int iter)
    {
        if (iter >= this->length)
            return 0;
        return head[iter];
    }
};


class Matrix
{
private:
    int rows;
    int columns;
    MyVector **h;

public:
    /*Matrix()
    {
        rows = 1;
        columns = 1;
        h = nullptr;
    }*/
    Matrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        h = new MyVector*[columns];
        for (int i = 0; i < columns; i++)
        {
            h[i] = new MyVector(rows);
        }
    }
    ~Matrix()
    {        
        for (int i = 0; i < columns; i++)
        {
            delete h[i];
        }
        delete[] h;
    }
    void print()
    {
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << (*h[i])[j] << ' ';
            }
            cout << endl;
        }
    }
    void sort()
    {
        for (int i = 0; i < (columns - 1); i++)
        {
            for (int j = 0; j < (columns - 1 - i); j++)
            {
                if ((*h[j])[0] > (*h[j + 1])[0])
                {
                    MyVector *temp = h[j];
                    h[j] = h[j + 1];
                    h[j + 1] = temp;
                }
                
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите размеры матрицы: " << endl;
    int rw, clmn;
    cin >> rw >> clmn;
    if (rw < 1) { rw = 1; }
    if (clmn < 1) { clmn = 1; }
    Matrix a(rw, clmn);
    cout << "Матрица до сортировки: " << endl;
    a.print();
    cout << endl;
    cout << "Матрица после сортировки: \n";
    a.sort();
    a.print();
    return 0;    
}

