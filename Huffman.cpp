#include<bits/stdc++.h>
using namespace std;
//树的节点
struct Node
{
    int value;
    Node *left,*right;
};
//优先队列
class  Priority_Queue
{
    vector<Node*> Data;
    int  Lenght;
    //建堆
    void  build_heap()
    {
        for(int i=Lenght/2;i>=0;--i)
        {
            heap(i);
        }
    }
    //堆整理
    void heap(int index)
    {
        int minvalue=index;
        while (true)
        {
            minvalue = index;
            if(index*2+1 < Lenght && Data.at(index*2+1)->value < Data.at(minvalue)->value)
            {
                minvalue = index*2+1;
            }
            if(index*2+2 < Lenght && Data.at(index*2+2)->value < Data.at(minvalue)->value)
            {
                minvalue = index*2+2;
            }
            if(minvalue==index)
                break;
            else
            {
                swap(Data[minvalue],Data[index]);
            }
            index = minvalue;
        }
    }
    public:
    Priority_Queue(vector<Node*> &Data)
    {
       this->Data = vector<Node*>(Data);
       Lenght = Data.size();
       build_heap();
    }
    //返回头节点
    Node* top()
    {
        return Data.at(0);
    }
    //删除头节点
    Node* pop()
    {
        swap(Data[0],Data[Lenght-1]);
        Lenght-=1;
        heap(0);
        return Data.at(Lenght);
    }
    //向队列插入新的节点
    void insert(Node *A)
    {
        Data.push_back(A);
        swap(Data[Data.size()-1],Data[Lenght]);
        Lenght+=1;
        build_heap();
    }
    //判断当前队列是否为空
    bool empty()
    {
        if(Lenght==0)
            return true;
        else
        {
            return false;
        }
    }
    //返回队列长度
    int lenght()
    {
        return Lenght;
    }
    ~Priority_Queue()
    {

    }
};
class Huffman
{
    Priority_Queue *P;
    Node *head;
    //Huffman树的先序遍历
    void PreOrder(Node *first)
    {
        if(first==NULL)
        {
            cout<<"#\t";
            return;
        }
        cout<<first->value<<"\t";
        PreOrder(first->left);
        PreOrder(first->right);
    }
    void Delete_tree(Node *first)
    {
        if(first==NULL)
            return;
        PreOrder(first->left);
        PreOrder(first->right);
        delete first;
    }
    void build_tree()
    {
        while (P->lenght()!=1)
        {
            head = new Node;
            head->left = P->pop();
            head->right = P->pop();
            head->value = head->left->value+head->right->value;
            P->insert(head);
        }
    }
    public:
    Huffman(vector<Node*>P)
    {
        this->P = new Priority_Queue(P);
        head = this->P->top();
        build_tree();
    }
    //先序遍历
    void PreOrder()
    {
        PreOrder(head);
    }
    //析构
    ~Huffman()
    {
        Delete_tree(head);
    }
};
int main()
{
    vector<Node*> MM;
    int n;
    cout<<"输入随机生成的节点数目：";
    cin>>n;
    cout<<"生成结果：";
    for(int i=0;i<n;++i)
    {
        Node *A = new Node;
        A->value=rand()%100;
        A->left=NULL;
        A->right=NULL;
        MM.push_back(A);
        cout<<A->value<<'\t';
    }
    cout<<"\nHuffman树的先序遍历：";
    Huffman H = Huffman(MM);
    H.PreOrder();
    system("pause");
}