#include <iostream>
#include<string>
using namespace std;
class SV {
    string lop;
    string hoten;
public:
    virtual void Nhap();
    virtual void Xuat();
};
void SV::Nhap() {
    fflush(stdin);
    cout << "\nNhap ho ten sinh vien: ";
    getline(cin, hoten);
    cout << "\nNhap lop hoc: ";
    fflush(stdin);
    getline(cin, lop);
}
void SV::Xuat() {
    cout << "\nHo ten sinh vien la: " << hoten;
    cout << "\nLop: " <<lop;
}
class SVSP :public SV {
private:
      float hb;
public:
    void Nhap();
    void Xuat();
};
void SVSP::Nhap() {
    SV::Nhap();
    cout << "\nNhap hoc bong cua ban: ";
    cin >> hb;
    }
void SVSP::Xuat() {
    SV::Xuat();
    cout << "\nHoc bong cua ban: " << hb;
}
class SVTC :public SV {
private:
    float hocphi;
public:
    void Nhap();
    void Xuat();
};
void SVTC::Nhap() {
    SV::Nhap();
    cout << "\nNhap muc hoc phi: ";
    cin >> hocphi;
}
void SVTC::Xuat() {
    SV::Xuat();
    cout << "\nMuc hoc phi cua ban la: " << hocphi;
}
int main()
{
    int n, m,luachon;
    cout<<"\nNhap so luong sinh vien su pham: ";
    cin >> n;
    cout<<"\nNhap so luong sinh vien tai chuc: ";
    cin >> m;
    SV* a = new SVSP[n];
    SV* b = new SVTC[m];
    while(1){
    	system("cls");
    cout<<"\n1.Nhap sinh vien su pham ";
	cout<<"\n2.Nhap sinh vien tai chuc ";
	cout<<"\n3.Xuat sinh vien su pham ";
	cout<<"\n4.Xuat sinh vien tai chuc ";
	cout<<"\n5.Thoat";
	cout<<"\nNhap lua chon cua ban ";
	cin>>luachon;
    switch(luachon){
    	case 1:
    		for (int i = 0; i <n; i++) {
               (a+i)->Nhap();
             }
             break;
        case 2:
        	for (int i = 0; i <m; i++) {
               (b+i)->Nhap();
             }
             break;
        case 3:
        	for (int i = 0; i <n; i++) {
               (a+i)->Xuat();
             }
             break;
        case 4:
        	for (int i = 0; i <m; i++) {
               (b+i)->Xuat();
             }
             break;
     	case 5:
     		exit(1);
	}
	cout<<"\nNhan ENTER de tiep tuc"<<endl;
	system("pause");
}
   delete a;
   delete b;
   system("pause");
   return 0; 
}


