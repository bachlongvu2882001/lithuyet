#include<iostream>
#include<string>
using namespace std;
class SV{
public:
    string lop;
    string ht;
    void Nhap();
     void Xuat();
};
void SV::Nhap(){
cout<<"\nNhap ho ten sinh vien =  ";
cin.ignore(1);
getline(cin,ht);
cin.ignore(1);
cout<<"\nNhap lop =  ";
getline(cin,lop);
}
void SV::Xuat(){
    cout<<"\nTen sinh vien la =  "<<ht;
    cout<<"\nLop =  "<<lop;
}
class SVTC:public SV{
   public:
       float hocphi;
      
       void Nhap();
       void Xuat();
};
void SVTC::Nhap(){
    SV::Nhap();
    cout<<"\nMuc hoc phi =  ";
    cin>>hocphi;
}
//Xuat hoc phi
void SVTC::Xuat(){
    SV::Xuat();
    cout<<"\nHoc phi =  "<<hocphi;
}
int main(){
  SVTC a;
  a.Nhap();
  a.Xuat();
    system("pause");
    return 0; 
}