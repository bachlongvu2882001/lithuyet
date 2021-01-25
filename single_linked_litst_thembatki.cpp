// Ki thuat th�m 1 node p v�o sau node q
#include<iostream>
using namespace std;

// Nh?p danh s�ch ki�n ket don c�c s? nguy�n
// ============ KHAI B�O Cau TR�C DANH S�CH LI�N K?T �ON ============
struct node
{
	int data; // d? li?u c?a 1 node
	struct node *pNext; // con tr? d�ng d? li�n k?t gi?a c�c node v?i nhau
};
typedef struct node NODE;

// khai b�o c?u tr�c danh s�ch li�n k?t don
struct list
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
// ============ KH?I T?O C?U TR�C DANH S�CH LI�N K?T �ON ===========
void KhoiTaoDSLK(LIST &l)
{
	// cho 2 node d?u v� cu?i tr? d?n v�ng nh? r?ng
	l.pHead = NULL;
	l.pTail = NULL;
}

// h�m kh?i t?o 1 c�i node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // g�n x cho data
	p->pNext = NULL;
	return p;
}


// h�m th�m node p v�o d?u danh s�ch
void ThemVaoDau(LIST &l, NODE *p)
{
	// danh s�ch dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // d�ng con tr? c?a node p li�n k?t v?i l.pHead
		l.pHead = p; // c?p nh?t l?i l.pHead l� p
	}
}

// h�m th�m node p v�o cu?i danh s�ch
void ThemVaoCuoi(LIST &l, NODE *p)
{
	// danh s�ch dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; // c?p nh?t l?i l.pTail l� p
	}
}

// xu?t danh s�ch li�n k?t don
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// Th�m node p v�o sau node q(n?m trong danh s�ch li�n k?t don)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// n?u danh s�ch ch? c� 1 ph?n t? v� ph?n t? d� cung ch�nh l� node q ==> b�i to�n tr? th�nh ki thu?t th�m v�o cu?i danh s�ch
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		// duy?t t? d?u danh s�ch d?n cu?i danh s�ch d? t�m node q
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			// n?u node q c� t?n t?i th�....
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // kh?i t?o node h m?i d? th�m v�o sau node q 
				NODE *g = k->pNext; // cho node g tr? d?n node n?m sau node q
				h->pNext = g; // Bu?c 1: T?o m?i li�n k?t t? node h d?n node g <=> cung ch�nh l� t?o m?i li�n k?t t? node h d?n node n?m sau node q
				k->pNext = h; // Bu?c 2: T?o m?i li�n k?t t? node q d?n node h <=> ch�nh l� node k d?n node h
			}
		}
	}
}

// menu
void Menu(LIST &l)
{
	int luachon;
	while (69)
	{
		system("cls");
		cout << "\n\n\t\t========== Menu ==========";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Them node p vao sau node q trong danh sach";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== End ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 3)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
			system("pause"); // d?ng m�n h�nh
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x); // kh?i t?o 1 c�i node
			ThemVaoCuoi(l, p); // th�m node v�o cu?i danh s�ch
		}
		else if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l, p); // th�m node p v�o sau node q trong danh s�ch l
		}
		else
		{
			break; // tho�t kh?i v�ng l?p hi?n t?i
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDSLK(l); // lu�n lu�n g?i h�m kh?i t?o danh s�ch li�n k?t don tru?c khi thao t�c v?i danh s�ch
	Menu(l);

	system("pause");
	return 0;
}
