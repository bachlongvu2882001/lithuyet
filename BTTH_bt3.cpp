#include<iostream>
using namespace std;
class MatHang{
	private:
	   string ten;
	public:
	   virtual void Nhap();
	   virtual void Xuat();
};
void MatHang::Nhap(){
	cin.ignore(1);
	cout<<"\nNhap ten mat hang: ";
	getline(cin,ten);
}
void MatHang::Xuat(){
	cout<<"\nTen mat hang la: "<<ten;
}
class MayTinh:public MatHang{
   private: 
      int speed;
	public:
	  void Nhap();
	  void Xuat();
};
void MayTinh::Nhap(){
	MatHang::Nhap();
	cout<<"\nNhap toc do cua may tinh: ";
	cin>>speed;
}
void MayTinh::Xuat(){
	MatHang::Xuat();
	cout<<"\nToc do cua may tinh: "<<speed;
}
class MayIn: public MatHang{
   private: 
      int Dpi;
	public:
	 void Nhap();
	 void Xuat();
};
void MayIn::Nhap(){
	MatHang::Nhap();
	cout<<"\nNhap do phan giai cua may in: ";
	cin>>Dpi;
}
void MayIn::Xuat(){
	MatHang::Xuat();
	cout<<"\nDo phan giai cua may in: "<<Dpi;
}
int main(){
	int n, m,luachon;
    cout<<"\nNhap so luong cho may tinh: ";
    cin >> n;
    cout<<"\nNhap so luong cho may in: ";
    cin >> m;
    MatHang* a = new MayTinh[n];
    MatHang* b = new MayIn[m];
    while(1){
    	system("cls");
    cout<<"\n1.Nhap cho may tinh ";
	cout<<"\n2.Nhap cho may in ";
	cout<<"\n3.Xuat may tinh ";
	cout<<"\n4.Xuat may in ";
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