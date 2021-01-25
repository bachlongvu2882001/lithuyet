#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class people{
	private:
		string hoten,diachi,gtinh;
		int tuoi;
	public:
		friend istream &operator>>(istream &is,people &a);
		friend ostream &operator<<(ostream &out,people &a);
};
class student:public people{
	private:
		int mssv;
		float toan,li,hoa;
	public:
	    friend istream &operator>>(istream &is,student &a);
	    friend ostream &operator<<(ostream &out,student &a);
		float diemTB();
};
istream &operator>>(istream &is,people &a){
	cout<<"Nhap ten ";
	getline(is,a.hoten);
	cout<<"Nhap dia chi ";
	getline(is,a.diachi);
	cout<<"Nhap tuoi ";
    is>>a.tuoi;
    is.ignore(1);
	cout<<"Nhap gioi tinh ";
	getline(is,a.gtinh);
	return is;
}
ostream &operator<<(ostream &out,people &a){
	out<<"Ten cua ban la "<<a.hoten<<endl<<"Dia chi la "<<a.diachi<<endl 
	<<"Gioi tinh la "<<a.gtinh<<endl<<"Tuoi la "<<a.tuoi<<endl;
	return out;
}
istream &operator>>(istream &is,student &a){
	
	cout<<"Nhap ma so sinh vien ";
	is>>a.mssv;
	cout<<"Nhap diem toan li hoa ";
	is>>a.toan>>a.li>>a.hoa;
}
ostream &operator<<(ostream &out,student &a){
	cout<<"Ma so sinh vien la "<<a.mssv<<endl;
	cout<<"Diem trung binh la "<<setprecision(2)<<fixed
	<<a.diemTB()<<endl;
}
float student::diemTB(){
	return (toan+li+hoa)/3;
}
int main()
{
	student A;
	cin>>A;
	cout<<A;
	
	
}
