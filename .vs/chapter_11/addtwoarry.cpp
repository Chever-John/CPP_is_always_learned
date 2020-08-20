#include<iostream>
using namespace std;

int main()
{
    int a[3] = {1,2,3};
    int b[3] = {1,2,3};
    int evening[6];
    for (int i = 0; i < 3; i++)
    {
        evening[i] = a[i] + b[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cout <<  evening[i] << ' ';
    }
    return 0;
    
}