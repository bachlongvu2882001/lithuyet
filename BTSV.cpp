#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class NhanVien{
    private:
        string mnv;
        string ht;
        int ns;
        string phong;
        double luong;
    public:
        
        friend ostream &operator<<(ostream &os, NhanVien &nv);
        friend istream &operator>>(istream &is, NhanVien &nv);
        bool operator < (NhanVien nv);
        bool operator > (NhanVien nv);
        bool operator == (NhanVien nv);
        float getluong();
        int getns();
};
istream &operator>>(istream &is, NhanVien &nv){
	cout<<"Nhap ma so nhan vien: ";
    cin.ignore();
	getline(is,nv.mnv);
	cout<<"Nhap ho va ten: ";
	cin.ignore();
	getline(is,nv.ht);
	cout<<"Nhap nam sinh: ";
	is>>nv.ns;
	cout<<"Nhap phong ban: ";
	cin.ignore();
	getline(is, nv.phong);
	cout<<"Nhap muc luong: ";
	is>>nv.luong;
	return is;
}
ostream &operator<<(ostream &os,NhanVien &nv){
    int n;
   os<<setw(10)<<left<<"MNV";
   os<<setw(20)<<left<<"HTen";
   os<<setw(15)<<left<<"NamSinh";
   os<<setw(10)<<left<<"Phong";
   os<<setw(10)<<left<<"Luong"<<endl;
   
   os<<setw(10)<<left<<nv.mnv;
   os<<setw(20)<<left<<nv.ht;
   os<<setw(15)<<left<<nv.ns;
   os<<setw(10)<<left<<nv.phong;
   os<<setw(10)<<left<<nv.luong<<endl;

return os;
}
void Nhap(int n, NhanVien *nv){
	for(int i=0;i<n;i++){
		cin>>*(nv+i);
	}
}
void Xuat(int n, NhanVien *nv){
    
    for(int i=0; i<n; i++){
        cout<<*(nv+i);
    }  
}
void swap(NhanVien *a,NhanVien *b){
    NhanVien c=*a;
	         *a = *b;
	         *b = c;
}
float NhanVien::getluong(){
    return this->luong;
}
int NhanVien::getns(){
    return this->ns;
}
void Sapxepns(int n, NhanVien *a){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((a+i)->getns() > (a+j)->getns())
            swap((a+i), (a+j));
        }
    }
    Xuat(n,a);
}
void Sapxepluong(int n,NhanVien *a){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((a+i)->getluong() < (a+j)->getluong())
            swap((a+i), (a+j));
        }
    }
    Xuat(n,a);
}
int Thongke(int n, NhanVien *a){
    int dem=0;
    for(int i=0; i<n; i++){
        if(a->getluong() > 10000){
        dem++;}
    }
    return dem;
}
int main(){
    NhanVien *a;
    int n, k;
     do{
        system("cls");
		cout<<"Lua chon chuc nang"<<endl;
		cout<<"1. Nhap danh sach nhan vien"<<endl;
		cout<<"2. Xuat danh sach"<<endl;
		cout<<"3. Sap xep tang dan theo luong"<<endl;
        cout<<"4. Sap xep tang dan theo nam sinh"<<endl;
		cout<<"5. Thong ke luong nhan vien co muc luong tren 10tr."<<endl;
        cout<<"6. Thoat."<<endl;
		cin>>k;
        
		switch(k){
			case 1:
				 cout<<"Nhap so luong nhan vien: ";
				cin>>n;
				a = new NhanVien[n];
				Nhap(n, a);
                system("pause");
				break;
			case 2:
				 Xuat(n,a);
                 system("pause");
				break;
			case 3:
				Sapxepluong(n, a);
                system("pause");
				break;
            case 4: 
                Sapxepns(n, a);
                system("pause");
                break;
			case 5:
                cout<<"So luong nhan vien tren 10 tr la  "<<Thongke(n, a);
                system("pause");
                break;
            case 6:
				return 0;
			}
			
    }while(k!=6);
                delete(a);
                system("pause");
    return 0;
}
