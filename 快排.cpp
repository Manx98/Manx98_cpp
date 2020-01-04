#include <iostream>
#include <cstdlib>
using namespace std;

void QSort(int *A,int L,int R)
{
    int l =L, r=R;
    while(l<r)
    {
        while(A[l]<A[r])
        {
            r--;
        }
        if(l<r)
            swap(A[l],A[r]);
        while(A[l]<A[r])
        {
            l++;
        }
        if(l<r)
            swap(A[l],A[r]);
    }
    if(L<l)
        QSort(A,L,l);
    if(l+1<R)
        QSort(A,l+1,R);
}
int main(){
int A[100],n=5;
for(int i=0;i<n;++i)
{
    A[i] = rand()%100;
    cout<<A[i]<<'\t';
}
cout<<'\n';
QSort(A,0,n-1);
for(int i=0;i<n;++i)
{
    cout<<A[i]<<'\t';
}
}
