// Ki thuat thêm 1 node p vào sau node q
#include<iostream>
using namespace std;

// Nh?p danh sách kiên ket don các s? nguyên
// ============ KHAI BÁO Cau TRÚC DANH SÁCH LIÊN K?T ÐON ============
struct node
{
	int data; // d? li?u c?a 1 node
	struct node *pNext; // con tr? dùng d? liên k?t gi?a các node v?i nhau
};
typedef struct node NODE;

// khai báo c?u trúc danh sách liên k?t don
struct list
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
// ============ KH?I T?O C?U TRÚC DANH SÁCH LIÊN K?T ÐON ===========
void KhoiTaoDSLK(LIST &l)
{
	// cho 2 node d?u và cu?i tr? d?n vùng nh? r?ng
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm kh?i t?o 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // gán x cho data
	p->pNext = NULL;
	return p;
}


// hàm thêm node p vào d?u danh sách
void ThemVaoDau(LIST &l, NODE *p)
{
	// danh sách dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // dùng con tr? c?a node p liên k?t v?i l.pHead
		l.pHead = p; // c?p nh?t l?i l.pHead là p
	}
}

// hàm thêm node p vào cu?i danh sách
void ThemVaoCuoi(LIST &l, NODE *p)
{
	// danh sách dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; // c?p nh?t l?i l.pTail là p
	}
}

// xu?t danh sách liên k?t don
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// Thêm node p vào sau node q(n?m trong danh sách liên k?t don)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// n?u danh sách ch? có 1 ph?n t? và ph?n t? dó cung chính là node q ==> bài toán tr? thành ki thu?t thêm vào cu?i danh sách
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		// duy?t t? d?u danh sách d?n cu?i danh sách d? tìm node q
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			// n?u node q có t?n t?i thì....
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // kh?i t?o node h m?i d? thêm vào sau node q 
				NODE *g = k->pNext; // cho node g tr? d?n node n?m sau node q
				h->pNext = g; // Bu?c 1: T?o m?i liên k?t t? node h d?n node g <=> cung chính là t?o m?i liên k?t t? node h d?n node n?m sau node q
				k->pNext = h; // Bu?c 2: T?o m?i liên k?t t? node q d?n node h <=> chính là node k d?n node h
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
			system("pause"); // d?ng màn hình
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x); // kh?i t?o 1 cái node
			ThemVaoCuoi(l, p); // thêm node vào cu?i danh sách
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
			ThemNode_p_VaoSauNode_q(l, p); // thêm node p vào sau node q trong danh sách l
		}
		else
		{
			break; // thoát kh?i vòng l?p hi?n t?i
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDSLK(l); // luôn luôn g?i hàm kh?i t?o danh sách liên k?t don tru?c khi thao tác v?i danh sách
	Menu(l);

	system("pause");
	return 0;
}
