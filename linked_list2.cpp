#include <iostream>
#include <string>
using namespace std;

typedef struct SinhVien
{
    char maSV[8];
    char HoTen[40];
    char Lop[10];
    float diemTB;
} SV;
typedef struct NodeSV
{
    SV info;
    NodeSV *next;
} Node;
typedef struct ListSV
{
    Node *Tail;
    Node *Head;
} List;
//khao tao mot list rong
void CreateList(List &l)
{
    l.Head = l.Tail = NULL;
}
Node *GetNode(SV a)
{
    Node *p = new Node; // cap phat bo nho cho node
    if (p == NULL)
    {
        return NULL;
    }
    p->info = a;
    p->next = NULL;
    return p;
}
void AddHead(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        p->next = l.Head;
        l.Head = p;
    }
}
void AddTail(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        l.Tail->next = p;
        l.Tail = p;
    }
}
void AddAfterq2(List &l, Node *p, Node *q)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (l.Tail == q)
        {
            l.Tail = q;
        }
        else
            AddHead(l, q);
    }
}
void InPut(List &l, int n)
{
    CreateList(l); //khoi tao list moi
    for (int i = 1; i <= n; i++){
              SV a;
    cout << "ID : ";
    cin >> a.maSV;
    cout << "Full Name : ";
    cin >> a.HoTen;
    cout << "Class : ";
    cin >> a.Lop;
    cout << "Score Avg : ";
    cin >> a.diemTB;
    Node *p = GetNode(a);
    AddHead(l, p);
    }
        SV a;
    cout << "ID : ";
    cin >> a.maSV;
    cout << "Full Name : ";
    cin >> a.HoTen;
    cout << "Class : ";
    cin >> a.Lop;
    cout << "Score Avg : ";
    cin >> a.diemTB;
    Node *p = GetNode(a);
    AddHead(l, p);
}

// Ham in danh sach sinh vien
void OutPut(List l)
{
    for (Node *p = l.Head; l.Head != NULL; p = p->next)
    {
        cout << "Student ID : " << p->info.maSV;
        cout << "Full name : " << p->info.HoTen;
        cout << "Class : " << p->info.Lop;
        cout << "Score Avg : " << p->info.diemTB;
    }
}
int main()
{
    List l;
    int n = 2;
    InPut(l, n);
    OutPut(l);
    return 0;
}
