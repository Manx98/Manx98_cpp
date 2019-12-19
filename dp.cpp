#include <bits/stdc++.h>
using namespace std;
int times[100], n;
int main()
{
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; ++i)
        times[i] = rand() % n+1;
    sort(times, times + n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
        cout << times[i] << "\t";
    cout << "\n";
    for (int i = n - 1; i > 2; i -= 2)
    {
        if (times[0] + times[1]*2 + times[i] < times[0] * 2 + times[i - 1] + times[i])
        {
            sum += times[0] + times[1] + times[i];
        }
        else
        {
            sum += times[0] * 2 + times[i - 1] + times[i];
        }
    }
    if (n == 2)
        sum += times[0] + times[1] + times[2];
    if (n == 1)
        sum = times[0];
    cout << sum << "\n";
    system("pause");
}