#include <iostream>
#include <cstdlib>
using namespace std;
int cin_check()
{
    cout << "请输入正整数，输入'0'结束。\n";
    int x;
    cin >> x;
    if(x < 0) 
    {
        cout << "输入错误！输入必须为正整数。\n";
        exit(0);
    }
    return x;
}//0挺妙，直接当判断条件；
class List{
 public:
    List()
    : first(NULL), current(NULL){}
    void insert(int x);
    void print();
    ~List();
 private:
    class ListNode{
     public:
        int data;
        ListNode *next;
        ListNode(int x, ListNode *next = NULL)
        : data(x), next(next){}
    };
    ListNode *first, *current;
};
void List::insert(int x)
{
    if(first == NULL)
    {
        ListNode *newnode = new ListNode(x, NULL);
        first = newnode;
    }
    else
    {
        current = first;
        ListNode *p = current;
        if(x <= first->data) 
        {
            ListNode *newnode = new ListNode(x, first);
            first = newnode;
            return;
        }
        else
        {
            while(x > current->data)
            {
                p =current;
                if(current->next == NULL)
                {
                    ListNode *newnode = new ListNode(x, NULL);
                    p->next = newnode;
                    return;
                }
                else
                {
                    current = current->next;
                }
            }
            ListNode *newnode = new ListNode(x, current);
            p->next = newnode;
        }
    }
}
void List::print()
{
    cout << "开始打印单链表\n";
    int i = 1;
    current = first;
    while(current)
    {
        cout << '[' << i << ']' << current->data << "->";
        current = current->next;
        i++;
    }
    cout << "end~";
    cout << "\n单链表打印结束\n";
}
List::~List()
{
    ListNode *p = current;
    for(current = first; (p = current) != NULL;)
    {
        current = current->next;
        cout << "释放结点" << endl;
        delete p;
    }
}
int main()
{
    List a;
    while(int x = cin_check())
    {
        a.insert(x);
    }
    a.print();
    return 0;
}