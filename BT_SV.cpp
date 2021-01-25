#include<iostream>
#include<string>
using namespace std;
class Sinhvien{
	private:
		int MSV, Namsinh;
		string Hoten;
		string Lop;
		float DTB;
	public:
		Sinhvien();
		Sinhvien(int MSV, int Namsinh, string Hoten, string Lop, float DTB);
		~Sinhvien();
		float getDTB();
		friend istream &operator>>(istream &is, Sinhvien &SV);
		friend ostream &operator<<(ostream &os, Sinhvien &SV);
		bool operator>(Sinhvien SV);
		bool operator<(Sinhvien SV);
		bool operator==(Sinhvien SV);
};
//Ham tao day du tham so
Sinhvien::Sinhvien(int MSV, int Namsinh, string Hoten, string Lop, float DTB){
	this->MSV = MSV;
	this->Namsinh = Namsinh;
	this->Hoten = Hoten;
	this->Lop = Lop;
	this->DTB = DTB;	
}
//Ham tao khong co tham so
Sinhvien::Sinhvien(){
	this->MSV=0;
	this->Namsinh=0;
	this->Hoten="";
	this->Lop="";
	this-> DTB=0;
}
//Ham huy
Sinhvien::~Sinhvien(){}
//Toan tu nhap
istream &operator>>(istream &is, Sinhvien &SV){
	cout<<"Nhap ma so sinh vien: ";
	is>>SV.MSV;
	cout<<"Nhap ho va ten: ";
	cin.ignore();
	getline(is,SV.Hoten);
	cout<<"Nhap nam sinh: ";
	is>>SV.Namsinh;
	cout<<"Nhap lop: ";
	cin.ignore();
	getline(is, SV.Lop);
	cout<<"Nhap diem trung binh: ";
	is>>SV.DTB;
	return is;
}
//Toan tu xuat
ostream &operator<<(ostream &os, Sinhvien &SV){
	os<<"\tMSSV: "<<SV.MSV<<endl;
	os<<"\tHo ten: "<<SV.Hoten<<endl;
    os<<"\tNam sinh: "<<SV.Namsinh<<endl;
	os<<"\tLop: "<<SV.Lop<<endl;
	os<<"\tDiem trung binh: "<<SV.DTB<<endl;
	return os;
}
//Toan tu so sanh >
bool Sinhvien::operator>(Sinhvien SV){
	if(this->DTB>SV.DTB)
	return 1;
	return 0;
	//cach 2: return (this->DTB>SV.DTB?1:0);
}
//Toan tu so sanh <
bool Sinhvien:: operator<(Sinhvien SV){
	if(this->DTB<SV.DTB)
	return 1;
	return 0;
}
//Toan tu so sanh ==
bool Sinhvien:: operator==(Sinhvien SV){
	if(this->DTB==SV.DTB)
	return 1;
	return 0;
}
//Ham lay diem trung binh
float Sinhvien::getDTB(){
	return this->DTB;
}
//Nhap mot danh sach gom n sinh vien
void NhapDanhSachSV(int n, Sinhvien *SV){
	for(int i=0;i<n;i++){
		cin>>*(SV+i);
	}
}
//Xuat mot danh sach gom n sinh vien
void XuatDanhSachSV(int n, Sinhvien *SV){
	for(int i=0;i<n;i++){
		cout<<"************"<<endl;
		cout<<"Stt: "<<i+1<<endl;
		cout<<*(SV+i);
	}
}
//Dem so sinh vien bi canh cao hoc vu (diemTB<1.0)
void ThongKe(int n, Sinhvien *SV){
	int soluongcanhcao = 0;
	for(int i=0;i<n;i++){
		float t = (SV+i)->getDTB();
		if(t < 1){
			soluongcanhcao++;
		}
	}
	cout<<"So luong sinh vien canh cao: "<<soluongcanhcao<<endl;
}
//Ham hoan vi hai sinh vien
void swap(Sinhvien *a,Sinhvien *b)
{
	Sinhvien c=*a;
	*a = *b;
	*b = c;
}
//Ham sap xep diem trung binh theo diem giam dan
void SapxepDTB(int n,Sinhvien* SV)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if((SV+i)->getDTB()<(SV+j)->getDTB() )
				swap((SV+i),(SV+j));
	}
	XuatDanhSachSV(n,SV);
}

int main(){
	Sinhvien *SV;
	int n,luachon;
	system("cls");
	do{
	system("cls");
		cout<<"Lua chon chuc nang"<<endl;
		cout<<"1. Nhap danh sach sinh vien"<<endl;
		cout<<"2. Xuat danh sach"<<endl;
		cout<<"3. Sap xep tang dan theo diem"<<endl;
		cout<<"4. Thoat"<<endl;
		cin>>luachon;
		switch(luachon){
			case 1:
				cout<<"Nhap so luong sinh vien: ";
				cin>>n;
				SV = new Sinhvien[n];
				NhapDanhSachSV(n, SV);
				break;
			case 2:
				XuatDanhSachSV(n, SV);
				break;
			case 3:
				SapxepDTB(n, SV);
				break;
			case 4:
				exit(0);
			}
			
	}	while(1);
	delete(SV);
	return 0;
}	