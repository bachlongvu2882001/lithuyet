#include <iostream>
using namespace std;
class PhanSo{
	private:
		int Tuso;
		int Mauso;
	public:
		PhanSo();
		PhanSo(int _Tuso,int _Mauso);
		PhanSo(const int &a);
		~PhanSo();
		void Nhap();
		void Xuat();
		void set(int a,int b);
		int getTu();
		int getMau();
		PhanSo Nghichdao();
		PhanSo Rutgon();
		PhanSo operator+(PhanSo b);
		PhanSo operator-(PhanSo b);
		friend istream & operator  >> (istream &, PhanSo &b);
		friend ostream & operator << (ostream &,PhanSo &b);
		PhanSo operator*(PhanSo b);
		PhanSo operator/(PhanSo b);
		PhanSo operator>(PhanSo b);
		friend bool operator == (PhanSo a, PhanSo b);
		PhanSo operator ++();
		operator double();
};
PhanSo::PhanSo(){
	Tuso=0;
	Mauso=1;
}
PhanSo::PhanSo(int _Tuso , int _Mauso){
	Tuso=_Tuso;
	Mauso=_Mauso; 
}
PhanSo::PhanSo(const int &a){
	Tuso=a;
	Mauso=a;
}
PhanSo::~PhanSo(){
}
void PhanSo::set(int a , int b){
	Tuso =a;
	Mauso=b;	
}
int PhanSo::getTu()
{
   return this->Tuso;
}
int PhanSo::getMau()
{
	return this->Mauso;
}
void PhanSo::Nhap(){
	cout<<"Nhap tu: ";
	cin>>Tuso;
	do{
		cout<<"Nhap mau: ";
	    cin>>Mauso;
	}while(Mauso == 0);
}
void PhanSo::Xuat(){
	if(Tuso==0)
		cout<<Tuso;
	else if (Mauso==1)
		cout<<Tuso;
	else
		cout<<Tuso<<"/"<<Mauso<<endl; 
}
PhanSo PhanSo::Nghichdao(){
	if(Tuso!=0)
   		return PhanSo(Mauso,Tuso);
   	else
   		return PhanSo(Tuso,Mauso);
}
int UCLN(int a, int b){
	while(a!=b){
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
PhanSo PhanSo::Rutgon(){
	int a = UCLN(Tuso,Mauso);
	return PhanSo(Tuso/a,Mauso/a);
}

PhanSo PhanSo::operator+(PhanSo b)
{
	PhanSo tong;
	tong.Tuso=this->Tuso*b.Mauso+b.Tuso*this->Mauso;
	tong.Mauso=this->Mauso*b.Mauso;
	return tong;
}
PhanSo PhanSo::operator*(PhanSo b)
{
	PhanSo c;
	c.Tuso=this->Tuso*b.Tuso;
	c.Mauso=this->Mauso*b.Mauso;
	return c;
}

PhanSo PhanSo::operator/(PhanSo b){
	PhanSo thuong;
	thuong.Tuso=this->Tuso*b.Mauso;
	thuong.Mauso=this->Mauso*b.Tuso;
	return thuong;
}

    istream & operator >> (istream & is, PhanSo & b)
    {
    	cout <<"nhap tu: ";
    	is >>b.Tuso;
    	cout <<"nhap mau: ";
    	is >>b.Mauso;
	}
	ostream & operator <<(ostream & os,PhanSo &b){
		os<<b.Tuso<<"/"<<b.Mauso;
		
	}
	
	PhanSo PhanSo::operator-(PhanSo b)
{
	PhanSo a;
	a.Tuso=this->Tuso*b.Mauso-b.Tuso*this->Mauso;
	a.Mauso=this->Mauso*b.Mauso;
	return a;
}
PhanSo PhanSo::operator >(PhanSo b){
	PhanSo a;
	a.Tuso=this->Tuso*b.Mauso>b.Tuso*this->Mauso;
	a.Mauso=this->Tuso*b.Mauso;
	return a;
}
bool operator == (PhanSo a, PhanSo b)
{
	if ((double(a.Tuso)/a.Mauso)==(double(b.Tuso)/b.Mauso))
		return true;
	return false;
}

PhanSo PhanSo::operator ++(){
	PhanSo a;
	a.Tuso=this->Tuso+this->Mauso;
	a.Mauso=this->Mauso;
	return a;
}
PhanSo::operator double(){
	return ((double)this->Tuso/(double)this->Mauso);
} 
int main(){
	PhanSo a1(1,2),a2(2,2),a3(1,1),a4(2,5),c,d,e(1,3);
	double f=double(a1);
    cout<<endl;

//f=a1.double();
	cout<<f;
//	e.Xuat();
//	if(a1==e)
//		cout<<"\na1=e";
//	else
//		cout<<"\na1!=e";
//	c=a1+a2+a3+a4;
//	c.Xuat();
//	cout <<endl<<"nhap phan so: ";
//	cin >>c;
//	cout<<c;
//	c=a1-a2-a3-a4;
//	cout<<"\n";
//	c.Xuat();
//	c=a1*a2*a3*a4;
//	cout<<"\n";
//	cout<<c<<endl;
//	c=a1/a2/a3/a4;
//	cout<<c;
	system("pause");
    return 0;
}