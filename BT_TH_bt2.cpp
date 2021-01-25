#include<iostream>
using namespace std;
class Shape{
	public:
	virtual float DT()=0;
	virtual void Nhap()=0;
	virtual void HienThi()=0;
};
class Circle:public Shape{
	private:
		float bankinh;
	public:
	    void Nhap();
		float DT();
		void HienThi();	
};
void Circle::Nhap(){
	cout<<"\nNhap ban kinh hinh tron: ";
	cin>>bankinh;
}
float Circle::DT(){
	return bankinh*bankinh*3.14;
}
void Circle::HienThi(){
	cout<<"\nDien tich hinh tron la: "<<DT();
}
class Rectangle:public Shape{
	private:
		float cd,cr;
	public:
		void Nhap();
		float DT();
		void HienThi();	
};
void Rectangle::Nhap(){
	cout<<"\nNhap chieu dai va chieu rong: ";
	cin>>cd>>cr;
}
float Rectangle::DT(){
	return (cd+cr)*2;
}
void Rectangle::HienThi(){
	cout<<"\nDien tich hinh chu nhat la: "<<DT();
}
int main(){
	int n, m,luachon;
    cout<<"\nNhap so luong hinh tron can tinh: ";
    cin >> n;
    cout<<"\nNhap so luong sinh hinh chu nhat can tinh: ";
    cin >> m;
    Shape* a = new Circle[n];
    Shape* b = new Rectangle[m];
    while(1){
    	system("cls");
    cout<<"\n1.Nhap cho hinh tron: ";
	cout<<"\n2.Nhap cho hinh chu nhat: ";
	cout<<"\n3.Xuat dien tich hinh tron: ";
	cout<<"\n4.Xuat dien tich hinh chu nhat ";
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
               (a+i)->HienThi();
             }
             break;
        case 4:
        	for (int i = 0; i <m; i++) {
               (b+i)->HienThi();
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
