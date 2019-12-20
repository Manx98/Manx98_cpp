#include <iostream>
#include <windows.h>
using namespace std;
string Student[100];
bool ssex[100];
bool visited[100];
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int is;
        string s;
        cin >> is >> s;
        Student[i] = s;
        visited[i] = 0;
        ssex[i] = is;
    }
    for (int i = 0; i < n / 2; ++i)
    {
        for (int t = n-1; t >=n / 2; --t)
        {
            if (visited[t])
                continue;
            if (ssex[i] != ssex[t])
            {
                cout << Student[i] << " " << Student[t] << "\n";
                visited[i]=1;
                visited[t]=1;
                break;
            }
        }
    }
    system("pause");
}