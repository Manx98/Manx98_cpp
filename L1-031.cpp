#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
int main()
{
    int n, w, h;
    while (n--)
    {
        cin >> h >> w;
        if (fabs(w/2 - (h - 100) * 0.9) <= (h - 100) * 0.9 * 0.1)
            cout << "You are wan mei!";
        else if (w/2  > (h - 100) * 0.9)
            cout << "You are tai pang le!";
        else
            cout << "You are tai shou le!";
    }

    system("pause");
}