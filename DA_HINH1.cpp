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
       /* NhanVien(string HoTen,int Tuoi, int BacLuong);
        ~NhanVien();*/
        virtual void Nhap(); //ham ao
        virtual void Xuat(); //ham ao
        virtual float TinhLuong() = 0; //ham thuan ao
        void setLoai(bool l);
        bool getLoai();
        virtual void MaxLuong();
};
 /*NhanVien::NhanVien(string HoTen,int Tuoi, int BacLuong)
 {
     this->HoTen = HoTen;
     this->Tuoi = Tuoi;
     this->BacLuong = BacLuong;
 }
NhanVien::~NhanVien(){}*/
void NhanVien::setLoai(bool l){
        LoaiNV=l;
}
bool NhanVien::getLoai(){
        return LoaiNV;
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
        cout<<"\tHo Ten= "<<HoTen<<endl;
        cout<<"\tTuoi= "<<Tuoi<<endl;
        cout<<"\tBac Luong "<<BacLuong<<endl;
}
class ChinhThuc: public NhanVien
{
    private:
        int ThamNien;
        vector <NhanVien *> DSNV;
    public:
       /* ChinhThuc(int ThamNien);
        ~ChinhThuc();*/
        void Nhap();
        void Xuat();
        float TinhLuong();
        void MaxLuong();
};
/*ChinhThuc::ChinhThuc(int ThamNien)
{
    NhanVien::NhanVien(string HoTen,int Tuoi, int BacLuong);
    this->ThamNien=ThamNien;
}*/
void ChinhThuc::MaxLuong(){
    DSNV *a;
    float max=a[0];
    for(int i=0;i<DSNV.size();i++){
    if(max<a[i]){
        max=a[i];
    }
}}
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
class ThuViec:public NhanVien
{
    private:
        string NgayVaoLam;
    public:
        //ThuViec();
        //~ThuViec();
        void Nhap();
        void Xuat();
        float TinhLuong();
};


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
        float TongLuong();
};
void CongTy::NhapDS(){
        int i=1,LuaChon;
        while(i){
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
float CongTy::TongLuong(){
           float sum=0;
            for(int i=0;i<DSNV.size();i++){
            sum+=DSNV[i]->TinhLuong();
            }
            return sum;
}
int main(){
            CongTy *a=new CongTy;
            a->NhapDS();
            cout<<"\n******************************"<<endl;
            a->XuatDS();
            cout<<"\n******************************"<<endl;
            cout<<"TONG LUONG NHAN VIEN: "<<a->TongLuong();
            delete a;
            system("pause");
            return 0;
}