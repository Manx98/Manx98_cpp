#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class MyNumber
{
private:
    int n;
    bool dfs(int num, int start, string path)
    {
        bool found = false;
        if (num == 0)
        {
            cout << path << "\t";
            found = true;
        }
        for (int i = start; i > 0 && num > 0; --i)
        {
            if (path.length() != 0)
            {
                found = dfs(num - i, i, path + "+" + String(i)) ? true : false;
            }
            else
            {
                if (dfs(num - i, i, path + String(i)))
                    cout << "\n\n";
            }
        }
        return found;
    }
    string String(int n)
    {
        string s = "";
        while (n)
        {
            int i = n % 10;
            n /= 10;
            s = char(i + '0') + s;
        }
        return s;
    }

public:
    MyNumber(int n)
    {
        this->n = n;
    }
    void start()
    {
        cout << "以下为所有加和结果：\n";
        dfs(n, n, "");
    }
};
int main()
{
    int n;
    cout << "输入一个整数：";
    cin >> n;
    MyNumber A = MyNumber(n);
    A.start();
    system("pause");
}