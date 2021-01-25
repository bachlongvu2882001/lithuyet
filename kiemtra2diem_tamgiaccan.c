#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
class Diem 
{
	private:
		int hoanhdo, tungdo;
	public:
		Diem();
		Diem(int a,int b);
		~Diem();
		void Nhap();
		void Xuat();
		friend float dodai(Diem a,Diem b);
		friend bool kiemtra(Diem a,Diem b,Diem c);
		float chuvi(Diem a,Diem b,Diem c);
		float canhday(Diem a,Diem b,Diem c);
		float chieucao(Diem a, Diem b,Diem c);
		float dientich(Diem a, Diem b,Diem c);
};
Diem :: Diem(){
	hoanhdo=0;
	tungdo=0;
}
Diem :: Diem(int a, int b){
	hoanhdo=a;
	tungdo=b;
}
Diem :: ~Diem(){
	
}
void Diem::Nhap(){
	cout<<"Nhap tung do va hoanh do "<<endl;
	cin>>tungdo>>hoanhdo;
}
void Diem::Xuat(){
	cout<<"("<<hoanhdo<<","<<tungdo<<")"<<endl;
}
float  dodai(Diem a, Diem b){
	return sqrt(pow(a.hoanhdo-b.hoanhdo,2)+pow(a.tungdo-b.tungdo,2));
}
float chuvi(Diem a, Diem b,Diem c){
	return dodai(a,b)+dodai(c,b)+dodai(a,c);
}
float canhday(Diem a, Diem b,Diem c){
	if(dodai(c,b)==dodai(a,c))
	   return  dodai(a,b);
	else if(dodai(a,b)==dodai(a,c))
	   return  dodai(c,b);
	else
	return dodai(a,c);
}
float chieucao(Diem a, Diem b,Diem c){
	float z=canhday(a,b,c)/2;
	if(dodai(c,b)==dodai(a,c))
		return sqrt(pow(dodai(c,b),2)-pow(z,2));
	else if (dodai(c,b)==dodai(a,b) )
	    return sqrt(pow(dodai(c,b),2)-pow(z,2));
	else return sqrt(pow(dodai(a,c),2)-pow(z,2));
	
}
bool kiemtra (Diem a,Diem b,Diem c){
	if(dodai(c,b)==0||dodai(a,b)==0||dodai(a,c)==0)
	  return 0;
	else if ((dodai(c,b)+dodai(a,b))<=dodai(a,c)||(dodai(c,b)+dodai(a,c))<=dodai(a,b)||(dodai(a,c)+dodai(a,b))<=dodai(c,b))
	return 0;
	else if(dodai(c,b)==dodai(a,b)||dodai(c,b)==dodai(a,c)||dodai(a,c)==dodai(a,b))
	return 1;
	else 
	return 0;
}
int main()
{
	Diem a(2,0),b(1,3),c(-1,1);
	a.Xuat();
	b.Xuat();
	c.Xuat();
	cout<<"Do dai cua diem la "<<setprecision(2)<<fixed<<dodai(a,b)<<endl;
	cout<<"Do dai cua diem la "<<dodai(c,b)<<endl;
	cout<<"Do dai cua diem la "<<dodai(a,c)<<endl;
	cout<<"Canh day la "<<canhday(a,b,c)<<endl;
	cout<<"Chieu cao cua tam giac la "<<chieucao(a,b,c)<<endl;
	if(kiemtra(a,b,c)==0)
	cout<<"Khong phai la tam giac can";
	else{
	cout<<"La tam giac can"<<endl;
	cout<<"Chu vi tam giac la "<<chuvi(a,b,c)<<endl;
    cout<<"Dien tich tam giac la "<<(canhday(a,b,c)*chieucao(a,b,c))/2<<endl;
    }
	system("pause");
	return 0;
}
