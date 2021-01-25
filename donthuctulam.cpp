#include <iostream>
#include <cmath>
using namespace std;
class DT
{
private:
	float heso;
	float somu;

public:
	DT();
	DT(float _heso, float _somu);
	DT(float _heso);
	~DT();
	friend istream &operator>>(istream &in, DT &temp);
	friend ostream &operator<<(ostream &out, const DT &temp);
	float operator+(DT dt1);
	float operator-(DT dt1);
	DT operator*(DT dt1);
	DT operator/(DT dt1);
	DT operator!();
	DT operator~();
	bool operator>(DT dt1);
	bool operator<(DT dt1);
	bool operator==(DT dt1);
	//DT operator++(DT dt1);
	//DT operator--(DT dt1);
	float GiaTri(float x);
	DT DaoHamBacK(int k);
};

DT::DT()
{
	this->heso = 0;
	this->somu = 0;
}

DT::DT(float _heso, float _somu)
{
	this->heso = _heso;
	this->somu = _somu;
}

DT::DT(float _heso)
{
	this->heso = _heso;
	this->somu = 1;
}

DT::~DT()
{
}

istream &operator>>(istream &in, DT &temp)
{
	cout << "\nNhap he so: ";
	in >> temp.heso;
	cout << "Nhap so mu: ";
	in >> temp.somu;
	return in;
}

ostream &operator<<(ostream &out, const DT &temp)
{
	if (temp.heso == 0)
	{
		cout << 0;
	}
	else if (temp.somu == 0)
	{
		cout << temp.heso;
	}
	else if (temp.somu == 1)
	{
		cout << temp.heso << "x";
	}
	else
	{
		cout << temp.heso << "x^" << temp.somu;
	}
	return out;
}

float DT::operator+(DT dt1)
{
	float x;
	cout << "\nNhap x: ";
	cin >> x;
	float giatri1 = this->GiaTri(x);
	float giatri2 = dt1.GiaTri(x);
	return giatri1 + giatri2;
}

float DT::operator-(DT dt1)
{
	float x;
	cout << "\nNhap x: ";
	cin >> x;
	float giatri1 = this->GiaTri(x);
	float giatri2 = dt1.GiaTri(x);
	return giatri1 - giatri2;
}

DT DT::operator*(DT dt)
{
	DT temp;
	temp.heso = this->heso * dt.heso;
	temp.somu = this->somu + dt.somu;
	return temp;
	//return DT(dt1.heso*dt2.heso,dt1.somu+dt2.somu);
}

DT DT::operator/(DT dt)
{
	DT temp;
	temp.heso = heso / dt.heso;
	temp.somu = somu - dt.somu;
	return temp;
}

//=========Dao ham bac 1===========
DT DT::operator!()
{
	DT temp;
	temp.heso = this->heso * this->somu;
	temp.somu = this->somu - 1;
	return temp;
}

DT DT::operator~()
{
	DT temp;
	this->somu++; //dt1.somu=dt1.somu + 1
	temp.somu = this->somu;
	temp.heso = this->heso / this->somu;
	return temp;
}
bool DT::operator>(DT dt1)
{
	float x;
	cout << "\nNhap x: ";
	cin >> x;
	float giatri1 = this->GiaTri(x);
	float giatri2 = dt1.GiaTri(x);
	return (giatri1 > giatri2) ? true : false;
}

bool DT::operator<(DT dt1)
{
	float x;
	cout << "\nNhap x: ";
	cin >> x;
	float giatri1 = this->GiaTri(x);
	float giatri2 = dt1.GiaTri(x);
	return (giatri1 < giatri2) ? true : false;
}
bool DT::operator==(DT dt1)
{
	float x;
	cout << "\nNhap x: ";
	cin >> x;
	float giatri1 = this->GiaTri(x);
	float giatri2 = dt1.GiaTri(x);
	return (giatri1 == giatri2) ? true : false;
}
//dinh nghia la toan tu ++, --
//DT a;
//a++ = a=a+1;

/*DT operator++(DT dt1){
 	DT temp;
 	temp.heso=dt1.heso+1;
 	temp.somu=dt1.somu+1;
 	return temp;
 }
 
 DT operator--(DT dt1){
 	DT temp;
 	temp.heso=dt1.heso-1;
 	temp.somu=dt1.somu-1;
 	return temp;
 }

 */
float DT::GiaTri(float x)
{
	return (this->heso * pow(x, this->somu));
}

DT DT::DaoHamBacK(int k)
{
	DT temp(this->heso, this->somu);
	for (int i = 1; i <= k; i++)
	{
		temp = !temp;
	}
	return temp;
}

int main()
{
	DT A, dt1, dt2, B;
	cout << "Nhap don thuc 1: ";
	cin >> dt1;
	cout << "Nhap don thuc 2";
	cin >> dt2;
	cout << "Don thuc 1 la: " << endl;
	cout << dt1 << endl;
	cout << "Don thuc 2 la: " << endl;
	cout << dt2 << endl;
	float a;
	a = dt1 + dt2;
	cout << "Tong hai don thuc la: " << endl;
	cout << a << endl;
	//	 	cout<<"Dao ham bac 1 cua dt1 la: ";
	//	 	B=!A;
	//	 	cout<<B;
	//	 	if(dt1>dt2)
	//	 		cout<<"1>2";
	//	 	else
	//	 	cout<<"1<=2";
	//	 	dt1=B.DaoHamBacK(3);
	//	 	cout<<dt1;
	system("pause");
	return 0;
}
