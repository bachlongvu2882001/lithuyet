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
int main(){
    Sinhvien sv;
    cin>>sv;
    cout<<sv;
    system("pause");
    return 0;
}