//Tim nhan vien co luong cao nhat
//Sap xep nhan vien theo luong giam dan
//Tim mot nhan vien bat ky
//Bo sung cac ham tao, ham huy cho cac class 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class NhanVien{
	protected:
		string HoTen;
		int Tuoi;
		int BacLuong;
		bool LoaiNV;
	public:
		NhanVien(); 
		NhanVien(string ht,int T,int B,bool L);
		~NhanVien();
		virtual void Nhap(); 
		virtual void Xuat(); 
		virtual float TinhLuong() = 0; 
		string getHoTen();
		void setLoai(bool l);
		bool getLoai();
};
string NhanVien::getHoTen(){
	return this->HoTen;
}
void NhanVien::setLoai(bool l){
	LoaiNV=l;
}
bool NhanVien::getLoai(){
	return LoaiNV;
}
class ChinhThuc: public NhanVien
{
	private:
		int ThamNien;
	public:
		ChinhThuc();
		ChinhThuc(string ht,int T,int B,bool L,int TN);
		~ChinhThuc();
		void Nhap();
		void Xuat();
		float TinhLuong();
};
class ThuViec:public NhanVien
{
	private:
		string NgayVaoLam;
	public:
		ThuViec();
		ThuViec(string ht,int T,int B,bool L,string NVL);
		~ThuViec();
		void Nhap();
		void Xuat();
		float TinhLuong();
};
// class nhan vien
NhanVien::NhanVien(){
	HoTen = "";
	Tuoi = 0;
	BacLuong = 0;
	LoaiNV = -1;
}
NhanVien::NhanVien(string ht,int T,int B,bool L){
	this->HoTen = ht;
	this->Tuoi = T;
	this->BacLuong = B;
	this->LoaiNV = L;
}
NhanVien::~NhanVien(){
}
void NhanVien::Nhap(){
	cout<<"\nNhap HoTen: ";
	cin.ignore(1);
	getline(cin,HoTen);
	cout<<"Nhap tuoi: ";
	cin>>Tuoi;
	cin.ignore(1);
	cout<<"Bac Luong: ";
	cin>>BacLuong;
}
void NhanVien::Xuat(){
	cout<<"\tHo Ten:  "<<HoTen<<endl;
	cout<<"\tTuoi: "<<Tuoi<<endl;
	cout<<"\tBac Luong: "<<BacLuong<<endl;	
}
//class chinh thuc
ChinhThuc::ChinhThuc(){
	HoTen = "";
	Tuoi = 0;
	BacLuong = 0;
	LoaiNV = -1;
	ThamNien = 0;
}
ChinhThuc::ChinhThuc(string ht,int T,int B,bool L,int TN){
	this->HoTen = ht;
	this->Tuoi = T;
	this->BacLuong = B;
	this->LoaiNV = L;
	this->ThamNien = TN;
}
ChinhThuc::~ChinhThuc(){
}
void ChinhThuc::Nhap(){
	NhanVien::Nhap();
	cout<<"Nhap tham nien: ";
	cin>>ThamNien;
}
void ChinhThuc::Xuat(){
	NhanVien::Xuat();
	cout<<"\tTham nien la: "<<ThamNien<<endl;
	cout<<"\tLuong: "<<this->TinhLuong();
}
float ChinhThuc::TinhLuong(){
	return (BacLuong*1600);
}
// class thu viec
ThuViec::ThuViec(){
	HoTen = "";
	Tuoi = 0;
	BacLuong = 0;
	LoaiNV = -1;
	NgayVaoLam = "";
}
ThuViec::ThuViec(string ht,int T,int B,bool L,string NVL){
	this->HoTen = ht;
	this->Tuoi = T;
	this->BacLuong = B;
	this->LoaiNV = L;
	this->NgayVaoLam = NVL;
}
ThuViec::~ThuViec(){
}
void ThuViec::Nhap(){
	NhanVien::Nhap();
	cout<<"Nhap ngay Vao Lam: ";
	cin.ignore(1);
	getline(cin,NgayVaoLam);
}
void ThuViec::Xuat(){
	NhanVien::Xuat();
	cout<<"\tNgay Vao Lam: "<<NgayVaoLam<<endl;
	cout<<"\tLuong: "<<this->TinhLuong()<<endl;
}
float ThuViec::TinhLuong(){ 
	return BacLuong*1600*0.8;
}
class CongTy{
	private:
		vector <NhanVien *> DSNV;
	public:
		void NhapDS();
		void XuatDS();
		void SapXep();
		void TimKiem(string f); // Tim kiem nhan vien
		void MaxLuong(); // Tim kiem nhan vien co luong cao nhat
		float TongLuong();
};
void CongTy::NhapDS(){
	int i=1,LuaChon;
	while(i){
		system("cls");
		cout<<"\n1. Nhap nhan vien chinh thuc."<<endl;
		cout<<"2. Nhap nhan vien thu viec."<<endl;
		cout<<"3. Thoat nhap"<<endl;
		NhanVien *nv;
		cout<<"Moi lua chon: ";
		cin>>LuaChon;
		system("cls");
		switch(LuaChon){
			case 1:
				nv=new ChinhThuc;
				nv->Nhap();
				DSNV.push_back(nv);
				nv->setLoai(true);
				break;
			case 2:
				nv=new ThuViec;
				nv->Nhap();
				DSNV.push_back(nv);
				nv->setLoai(false);
				break;
			case 3:
				i=0;
				break;
			default:
				cout<<"Nhap sai. Moi nhap lai"<<endl;
		}
	}
}
void CongTy::XuatDS(){
	for(int i=0;i<DSNV.size();i++){
		if(DSNV[i]->getLoai()==true){
			cout<<"\nNhan vien chinh thuc: "<<endl;
			DSNV[i]->Xuat();
		}
		else{
			cout<<"\nNhan vien thu viec: "<<endl;
			DSNV[i]->Xuat();
		}
	}
}
void CongTy::SapXep(){
	for(int i=0;i<DSNV.size();i++){ // thuat toan sap xep noi bot
		for(int j=i+1;j<DSNV.size();j++){
			if(DSNV[i]->TinhLuong() < DSNV[j]->TinhLuong() && DSNV[i]->TinhLuong() != DSNV [j]->TinhLuong()){
				swap(DSNV[i],DSNV[j]);
			}
		}
	}
	XuatDS();
}
void CongTy::TimKiem(string f){//Tim kiem nhan vien bat ki bang thuat toan tim kiem tuyen tinh
	cout << "\nTen nhan vien muon tim: " << endl;
	getline(cin,f);
	for(int i=0;i<DSNV.size();i++){
		if (DSNV[i]->getHoTen() == f){
			cout << "Nhan vien co trong danh sach"<<endl;
			if(DSNV[i]->getLoai()==true){
				cout<<"\nNhan vien chinh thuc: "<<endl;
				DSNV[i]->Xuat();
				return;
			}
			else{
					cout<<"\nNhan vien thu viec: "<<endl;
					DSNV[i]->Xuat();
					return;
			}	
		}
	}
	cout << "Nhan vien khong co trong danh sach"<<endl;	 
}
void CongTy::MaxLuong(){
	int max = DSNV[0]->TinhLuong();
	int temp=0;
	for(int i=1;i<DSNV.size();i++){
		if(max < DSNV[i]->TinhLuong()){
			max = DSNV[i]->TinhLuong();
			temp=i;
		}
	}
	cout << "Nhan Vien co Luong cao nhat" << endl;
	DSNV[temp]->Xuat();
}

float CongTy::TongLuong(){
	float sum=0;
	for(int i=0;i<DSNV.size();i++){
		sum+=DSNV[i]->TinhLuong();
	}
	return sum;
} 
int main(){
	string f;
	CongTy *a=new CongTy;
	a->NhapDS();
	cout<<"\n******************************"<<endl;
	a->XuatDS();
	cout<<"\n******************************"<<endl;
	cout << "\nSap xep nhan vien theo luong giam dan";
	a->SapXep();
	cout<<"\n******************************"<<endl;	
	cout <<"\nTim kiem nhan vien";
	cin.get();
	a->TimKiem(f);
	cout<<"\n******************************"<<endl;
	cout<<"\nTONG LUONG NHAN VIEN: "<<a->TongLuong();
	cout<<"\n******************************"<<endl;
	cout <<"\nTim luong cao nhat";
	a->MaxLuong();
	delete a;
	system("pause");
	return 0;
}
