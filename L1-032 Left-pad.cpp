#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    char full;
    string c;
    int n;
    cin>>n>>full;
    getline(cin,c);
    getline(cin,c);
    if(n>=c.size())
    {
        n-=c.size();
        while(n--)
            cout<<full;
        cout<<c;
    }
    else
    {
      for(int i=c.size()-n;i<c.size();++i)
                cout<<c[i];
    }
}
