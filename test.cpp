#include <bits/stdc++.h>
using namespace std;
//字典树的节点
struct Node
{
    //节点的值
    char chr;
    //是否为结尾
    bool end;
    //分支节点
    Node *other;
    //下一级节点
    Node *next;
    //初始化结构体
    Node()
    {
        other=NULL;
        next=NULL;
        end=false;
        chr='\n';
    }
};
class Trie {
    //树的头节点
    Node *header;
    //给与一个头节点，和一个字符，查询这个字符在当前链表中的位置，返回其的指针，不存在时返回末尾最后一个节点的指针
    Node* found(Node *H,char c)
    {
        Node *N = H,*p = H->other;
        while(p!=NULL)
        {
            N = p;
            if(p->chr==c)
                break;
            p=p->other;
        }
        return N;
    }
public:
    //初始化字典树
    Trie() {
        header = new Node();
    }
    
    //向字典树插入一个单词
    void insert(string word) {
        Node *H = header;
        for(int i=0;i<word.size();++i)
        {
            H = found(H,word[i]);
            //检测节点是否被查询到
            if(H->chr!=word[i])
            {
                //没有查询到节点
                //插入将word[i]插入为新节点
                Node *p = new Node();
                p->chr = word[i];
                p->other = H->other;
                H->other = p;
                //创建下一级节点
                p->next = new Node();
                //判断当前节点是否为word的结尾
                if(i+1==word.size())
                    p->end=1;
                H = p->next;
            }
            else
            {
                //查询到节点
                //判断当前节点是否为word的结尾
               if(i+1==word.size())
                    H->end=1;
                H = H->next; 
            }
        }
    }
    
    //查询word是否存在于树中
    bool search(string word) {
        int i=0;
        Node *p = header;
        for(;i<word.size();++i)
        {
            //查询节点
            p = found(p,word[i]);
            //判断是否查询到的节点
            if(p->chr!=word[i])
                break;
            //判断是否为结尾
            if(i+1==word.size()&&p->end)
                return 1;
            p = p->next;
        }
        return 0;
    }
    
    //查询prefix是否为某一个词的前缀
    bool startsWith(string prefix) {
        int i=0;
        Node *p = header;
        for(;i<prefix.size();++i)
        {
            p = found(p,prefix[i]);
            if(p->chr!=prefix[i])
                break;
            if(i+1==prefix.size())
                return 1;
            p = p->next;
        }
        return 0;
    }
};
int main()
{
Trie trie = Trie();
trie.insert("apple");
cout<<trie.search("apple")<<'\n';   // 返回 true
cout<<trie.search("app")<<'\n';     // 返回 false
cout<<trie.startsWith("app")<<'\n'; // 返回 true
trie.insert("app");   
cout<<trie.search("app")<<'\n';     // 返回 true
system("pause");
}