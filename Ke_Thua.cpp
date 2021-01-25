#include<iostream>
#include<string>

using namespace std;

class SV{
private:
    string lop;
    string ht;
public:
     SV(string lop,string ht);
     /*~SV();*/
     int Nhap();
     int Xuat();
};

//Ham tao day du tham so
SV :: SV(string lop, string ht){
    this->lop = lop;
    this->ht = ht;
}
//Ham huy
/*SV::~SV(){}*/
int SV::Nhap(){
cout<<"\nNhap ho ten sinh vien =  ";
getline(cin,ht);
cout<<"\nNhap lop =  ";
getline(cin,lop);
cin.ignore(1);

}
int SV::Xuat(){
    cout<<"\nTen sinh vien la =  "<<ht;
    cout<<"\nLop =  "<<lop;
}

class SVTC: public SV{
 private:
       float hocphi, hb;
 public:
       SVTC(float hocphi, float hb);
       void Nhap();
       void Xuat();
};
//Ham khoi tao hoc phi day du
SVTC::SVTC(float hocphi = 0.0,float hb = 0.0)   
{
    this->hocphi=hocphi;
    this->hb=hb;
}
//Nhap Bo sung hoc phi cho hoc sinh
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
/*class SVCN:public SVTC{
   protected:
       float dtb;
    public:
       void HocBong();
       SVCN(float dtb);
       void Nhap();
       void Xuat();
       bool operator>(SVCN &svcn);
};
/*Ham khoi tao
SVCN::SVCN(float dtb){
    this->dtb = dtb;
}
void SVCN::Nhap(){
    SVTC::Nhap();
    cout<<"\nNhap diem trung binh =  ";
    cin>>dtb;
}
void SVCN::Xuat(){
    SVTC::Xuat();
    cout<<"\nDiem trung binh =  "<<dtb;
}*/
int main(){
  SVTC a;
  a.Nhap();
  a.Xuat();
  system("pause");
  return 0; 
}