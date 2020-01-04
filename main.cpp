#include <bits/stdc++.h>
using namespace std;
int n, W;
int m[100];
int weight[100], value[100];
int dp()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int w = W; w >=0; --w)
        {
            if (weight[i] < w)
            {
                m[w] = max(m[w], m[w - weight[i]] + value[i]);
            }
        }
    }
    printf("备忘录：");
    for (int t = 0; t <= W; ++t)
    {
        printf("%d\t", m[t]);
    }
    printf("\n");
    return m[W];
}
int main()
{
    printf("输入可偷取数目：");
    cin>>n;
    printf("输入背包容量：");
    cin>>W;
    for (int i = 1; i <= n; ++i)
        cin>>weight[i]>>value[i];
    printf("最大可装价值：%d\n",dp()) ;
    system("pause");
}