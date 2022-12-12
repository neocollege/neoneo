#include <iostream>
#include <math.h>
#define ll long long
using namespace std;


int h1(string s, int arrSize)
{
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i]));
        hash = hash % arrSize;
    }
    return hash;
}


int h2(string s, int arrSize)
{
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + pow(19, i) * s[i];
        hash = hash % arrSize;
    }
    return hash % arrSize;
}


void lookup(int *bitarray1,int *bitarray2, int arrSize, string s)
{
    int a = h1(s, arrSize);
    int b = h2(s, arrSize);

    if (bitarray1[a] && bitarray2[b])
        cout << "Count of " << s << " is " << min(bitarray1[a],bitarray2[b]);
    else
        cout << s << "doesnt exist";
}

void insert(int *bitarray1,int *bitarray2, int arrSize, string s)
{
    int a = h1(s, arrSize);
    int b = h2(s, arrSize);
    bitarray1[a] += 1;
    bitarray2[b] += 1;
    cout << s << " inserted" << endl;
}

int main()
{
    const int arrSize = 10;
    int bitarray1[arrSize] = {0};
    int bitarray2[arrSize] = {0};
    string name;
    string sarray[] = {"jack","jack","jack","lane","lane","lane","lane","lane","bob","bob","bob","bob","bob","bob","alice","zuck","eve","max"};
    for (int i = 0; i < sizeof(sarray)/sizeof(sarray[0]); i++)
    {
        insert(bitarray1,bitarray2, arrSize, sarray[i]);
    }
    for (int i = 0; i < arrSize; i++)
    {
        cout << bitarray1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << bitarray2[i] << " ";
    }
    cout << endl;
    cout << "Enter name to lookup: ";
    cin >> name;
    lookup(bitarray1,bitarray2, arrSize,name);
    return 0;
}