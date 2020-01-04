#include <iostream>
#include <cstdlib>
using namespace std;
void Merge(int *A,int L,int mid,int J)
{
    int l =L,m =mid+1,j = J,k=0;
    int c[100];
    while(l<=mid&&m<=J)
    {
        if(A[l]<=A[m])
        {
            c[k++] = A[l++];
        }
        else
        {
            c[k++] = A[m++];
        }
    }
    while(m<=J)
    {
        c[k++] = A[m++];
    }
    while(l<=mid)
    {
        c[k++] = A[l++];
    }
    for(int i = 0; i<k; ++i)
    {
        A[L++] =c[i];
    }
}
void MergeSort(int *A,int L,int J)
{
    if(L<J)
    {
        int mid = (L+J)/2;
        MergeSort(A,L,mid);
        MergeSort(A,mid+1,J);
        Merge(A,L,mid,J);
    }
}

int main()
{
 int A[100];
 int n=5;
 for(int i=0;i<n;++i){
    A[i] = rand()%100;
    cout<<A[i]<<'\t';
 }
 cout<<endl;
 MergeSort(A,0,n-1);
 for(int i=0;i<n;++i){
    cout<<A[i]<<'\t';
 }
}

