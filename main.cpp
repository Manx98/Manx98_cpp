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
    printf("����¼��");
    for (int t = 0; t <= W; ++t)
    {
        printf("%d\t", m[t]);
    }
    printf("\n");
    return m[W];
}
int main()
{
    printf("�����͵ȡ��Ŀ��");
    cin>>n;
    printf("���뱳��������");
    cin>>W;
    for (int i = 1; i <= n; ++i)
        cin>>weight[i]>>value[i];
    printf("����װ��ֵ��%d\n",dp()) ;
    system("pause");
}