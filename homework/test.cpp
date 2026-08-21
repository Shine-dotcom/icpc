#include<iostream>
using namespace std;
#define int long long
#define endl '\n'
template <typename T>
class queue{
    private:
    struct Node{
        T data;
        Node* next;
    };
    Node* fr = NULL;
    Node* rear = NULL;
    int cnt = 0;
    public:
    void push(T x)
    {
        Node* p = new Node;
        p -> data = x;
        if(rear == NULL)
        {
            rear = fr = p;
        }
        else
        {
            rear -> next = p;
            rear = p;
        }
        cnt ++;
    }
    void pop()
    {
        if(rear == fr)
        {
            Node* p = rear;
            rear = fr = NULL;
            delete p;
            cnt --;
            return;
        }
        if(rear == NULL)
        {
            cout << "Queue Is Empty!" << endl;
            exit(-1);
        }
        Node* p = fr;
        fr = fr -> next;
        delete p;
        cnt --;
    }
    T front()
    {
        if(fr == NULL)
        {
            cout << "No Elements!" << endl;
            exit(-1);
        }
        return fr->data;
    }
    int size()
    {
        return cnt;
    }
};

signed main()
{
    queue<int> q;
    q.push(10);
    cout << q.front() << endl;
    q.push(20);
    cout << q.front() << endl;
    cout << q.size() << endl;
    q.push(30);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.size() << endl;
    // cout << q.front() << endl;
}