#include <bits/stdc++.h>
using namespace std;
int n,W;
int m[100][100];
int weight[100], value[100];
int dp()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            if (weight[t] > w)
            {
                m[i][w] = m[i - 1][m];
            }
            else
            {
                m[i][w] = max(m[i-1][w],m[i][w-weight[i]]+value[i]);
            }
        }
    }
    return m[n][W];
}
int main()
{
    cin >> n;
    cin >> W;
    for (int i = 1; i <= n; ++i)
        cin >> weight[i] >> value[i];
    cout << dp();
    system("pause");
}