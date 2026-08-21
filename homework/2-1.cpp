#include<bits/stdc++.h>
using namespace std;
struct LNode{
    int data;
    LNode* next;
};
signed main()
{
    LNode* L1 = new LNode;
    LNode* L2 = new LNode;
    L1 -> next = NULL;
    L2 -> next = NULL;
    int n, m;
    cin >> n >> m;
    LNode* p = L1;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        LNode* node = new LNode;
        node -> data = x;
        node -> next = p -> next;
        p -> next = node;
        p = p -> next;
    }
    L1 = L1 -> next;
    // cout << L1 -> data << endl;
    // for(LNode* i = L1 -> next; i != NULL; i = i -> next)
    // {
    //     cout << i -> data << ' ';
    // }
    // cout << endl;
    p = L2;
    for(int i = 1; i <= m; i ++ )
    {
        int x;
        cin >> x;
        LNode* node = new LNode;
        node -> data = x;
        node -> next = p -> next;
        p -> next = node;
        p = p -> next;
    }
    L2 = L2 -> next;
    LNode* q;
    for(p = L1, q = L2; p -> next != NULL; p = p -> next)
    {
        while(q -> next != NULL && q -> data >= p -> next -> data) q = q -> next;
        if(q -> data >= p -> data)
        {
            q -> next = p -> next;
            p -> next = q;
        }
        cout << q -> data << ' ' << p -> data << endl;
    }
    cout << "111" << endl;
    // while(q != NULL)
    // {
    //     q -> next = p -> next;
    //     p -> next = q;
    //     p = p -> next;
    // }
    // for(p = L1 -> next; p != NULL; p = p -> next)
    // {
    //     cout << p -> data << ' ';
    // }
    // cout << endl;
}