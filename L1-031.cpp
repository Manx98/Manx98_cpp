#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, w, h;
    cin>>n;
    while (n--)
    {
        cin >> h >> w;
        if (fabs(w - (h - 100) * 0.9*2) < (h - 100) * 0.9 * 0.1*2)
            cout << "You are wan mei!\n";
        else if (w  >= (h - 100) * 0.9*2)
            cout << "You are tai pang le!\n";
        else
            cout << "You are tai shou le!\n";
    }

}
