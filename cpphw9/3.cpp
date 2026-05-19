#include <iostream>
using namespace std;

template<typename T>
class NodeList {
 private:
    class Node {
     public:
        T data;
        Node* next;
        Node(const T& val) : data(val), next(NULL) {}
    };
    Node* head;
    int size;

 public:
    NodeList() : head(NULL), size(0) {}
    ~NodeList() 
    {
        Node* cur = head;
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
    void push_front(const T& val) 
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    void push_back(const T& val) 
    {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } 
        else 
        {
            Node* cur = head;
            while (cur->next)
            {
                cur = cur->next;
            } 
            cur->next = newNode;
        }
        size++;
    }
    void remove(const T& val) // 删除第一个值为val的Node
    {
        if (!head) 
        {
            cout << "链表为空" << endl;
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "成功删除 " << val << endl;
            size--;
            return;
        }
        Node* cur = head;
        while (cur->next && cur->next->data != val) {
            cur = cur->next;
        }
        if (cur->next) {
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            cout << "成功删除 " << val << endl;
            size--;
            return;
        }
        cout << "未找到欲删除值" << endl;
        return;
    }
    void print() const 
    {
        Node* cur = head;
        while (cur) 
        {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "-END-\n";
    }
    int get_size() const { return size; }
    bool empty() const { return (head == NULL); }
};

int main() {
    NodeList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.print(); // 预期 0 1 2
    list.remove(1);
    list.print();  // 预期 0 2
    cout << "size: " << list.get_size() << endl;
    return 0;
}