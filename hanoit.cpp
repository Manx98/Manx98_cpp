#include <bits/stdc++.h>
using namespace std;
struct prams{
    int n;
    char from,pass,to;
};
void hanoit(int num,char from,char pass,char to)
{
    stack <prams> S;
    prams node = {num,from,pass,to};
    while(!S.empty()||node.n!=0){
        while(node.n){
            S.push(node);
            swap(node.pass,node.to);
            node.n--;
        }
        node = S.top();
        S.pop();
        cout<<node.from<<"->"<<node.to<<"\n";
        node.n--;
        swap(node.from,node.pass);
    }
}
int main()
{
    int num = 3;
    hanoit(num,'A','B','C');
    system("pause");
}