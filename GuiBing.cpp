#include<bits/stdc++.h>
using namespace std;
void Merge(int *A,int *temp,int start , int end,int Mid)
{
    int m = Mid+1;
    int K = start;
    int s=start;
    while (s!=Mid+1&&m!=end+1)
    {
        if(A[s]<A[m])
            temp[K++]=A[s++];
        else
            temp[K++]=A[m++];
    }
    while (s!=Mid+1)
        temp[K++]=A[s++];
    while (m!=end+1)
        temp[K++]=A[m++];
    for(;start<=end;++start)
        A[start]=temp[start];
}
void Merge_Sort(int *A,int *temp,int start,int end)
{
    if (start<end)
    {
        int mid = (end+start)/2;
        Merge_Sort(A,temp,start,mid);
        Merge_Sort(A,temp,mid+1,end);
        Merge(A,temp,start,end,mid);
    }
}
int main()
{
    int size,A[100],temp[100];
    cin>>size;
    for(int i=0;i<size;++i)
        A[i]=rand()%100;
    Merge_Sort(A,temp,0,size-1);
    for(int i=0;i<size;++i)
        cout<<A[i]<<"\t";
    system("pause");
}