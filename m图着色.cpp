#include<iostream>
using namespace std;
class ColorMap
{
    bool MAP[100][100];
    int Color[100];
    int node_num;
    string ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public:
    ColorMap(int n,int bian)
    {
        cout<<"�����ڽӹ�ϵ\n";
        node_num = n;
        for(int i=0; i<bian; ++i)
        {
            int a,b;
            cin>>a>>b;
            MAP[a-1][b-1] = MAP[b-1][a-1] = 1;
            Color[i]=0;
        }
    }
    bool canDraw(int a)
    {
        for(int i=0; i<node_num; ++i)
        {
            if(MAP[a][i]&&i!=a)
            {
                if(Color[a]==Color[i])
                    return 0;
            }
        }
        return 1;
    }
    void draw(int numColor)
    {
        int n=1;
         draw(0,numColor,n);
    }
    void draw(int deep,int numColor, int &N)
    {
        if(deep==node_num)
        {
            show(N);
            N+=1;
            return ;
        }
        for(int t=1; t<=numColor; ++t)
        {
            Color[deep] = t;
            if(canDraw(deep)){
                draw(deep+1,numColor,N);
            }
            Color[deep] = 0;
        }
    }

    void show(int n)
    {
        cout<<'\n';
        cout<<"��"<<n<<"��Ϳɫ������"<<"\n";
        for(int i=0; i<node_num; ++i)
            cout<<ch[i]<<" ��Ϳ�� "<<Color[i]<<" ����ɫ\n";
    }
};
/*
5 8
4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5
*/
int main()
{
    int bian,node_num,numColor;
    cout<<"���붥�����ͱ�����";
    cin>>node_num>>bian;
    cout<<"������ɫ��Ŀ��";
    cin>>numColor;
    ColorMap MAP(node_num,bian);
    MAP.draw(numColor);
}
