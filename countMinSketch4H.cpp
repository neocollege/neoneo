#include <bits/stdc++.h>
using namespace std;
int matrix[4][16];
int hash1(int ele)
{
    int a = ele % 16;
    return a;
};
int hash2(int ele)
{
    int el = ele * 2;
    int b = el % 16;
    return b;
};
int hash3(int ele)
{
    int el = ele * 3;
    int c = el % 16;
    return c;
};
int hash4(int ele)
{
    int el = ele * 4;
    int d = el % 16;
    return d;
};

void insert_element(int element)
{
    int a = hash1(element);
    int b = hash2(element);
    int c = hash3(element);
    int d = hash4(element);
    matrix[0][a] = matrix[0][a] + 1;
    matrix[1][b] = matrix[1][b] + 1;
    matrix[2][c] = matrix[2][c] + 1;
    matrix[3][d] = matrix[3][d] + 1;
};

void print()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
};

int check_count(int element)
{
    int a = hash1(element);
    int b = hash2(element);
    int c = hash3(element);
    int d = hash4(element);
    int c1 = matrix[0][a];
    int c2 = matrix[1][b];
    int c3 = matrix[2][c];
    int c4 = matrix[3][d];

    if (c1 < c2)
    {
        c = c1;
    }
    else
    {
        c = c2;
    }
    if (c3 < c4)
    {
        d = c3;
    }
    else
    {
        d = c4;
    }
    if (c < d)
    {
        return c;
    }
    else
    {
        return d;
    }
};

int main()
{
    void insert_element(int);
    int hash1(int);
    int hash2(int);
    int hash3(int);
    int hash4(int);
    int check_count(int);
    void print();
    insert_element(20);
    print();
    insert_element(30);
    print();
    insert_element(40);
    print();
    insert_element(20);
    print();

    int count = check_count(20);
    cout << "This element is processed " << count << " times";
    return 0;
}