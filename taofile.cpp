#include<iostream>
#include<string>
using namespace std;

class NV{
    private:
        string MaNV;
        string hoten;
        int ns;
        string phongban;
        double luong;
    public:
        
        friend ostream &operator<<(ostream &os, NV &nv);
        friend istream &operator>>(istream &is, NV &nv);
        bool operator < (NV nv);
        bool operator > (NV nv);
        bool operator == (NV nv);
        
};
istream &operator>>(istream &is, NV &nv){
	cout<<"Nhap ma so nhan vien: ";
    cin.ignore();
	getline(is,nv.MaNV);
	cout<<"Nhap ho va ten: ";
	cin.ignore();
	getline(is,nv.hoten);
	cout<<"Nhap nam sinh: ";
	is>>nv.ns;
	cout<<"Nhap phong ban: ";
	cin.ignore();
	getline(is, nv.phongban);
	cout<<"Nhap muc luong: ";
	is>>nv.luong;
	return is;
}
ostream &operator<<(ostream &os, NV &nv){
	cout<<"\tMa nhan vien: "<<nv.MaNV<<endl;
	cout<<"\tHo ten: "<<nv.hoten<<endl;
	cout<<"\tNam sinh: "<<nv.ns<<endl;
	cout<<"\tPhong ban: "<<nv.phongban<<endl;
	cout<<"\tMuc luong: "<<nv.luong<<endl;
	return os;
}
void NhapDSNV(int n, NV *nv){
	for(int i=0;i<n;i++){
		cin>>*(nv+i);
	}
}
void XuatDSNV(int n, NV* nv){
    
    for(int i=0; i<n; i++){
        cout<<"-----"<<endl;
        cout<<"STT: "<<i + 1<<endl;
        cout<<*(nv+i);
    }
    
    
}
int main(){
    NV *a;
    int n, k;
    cout<<"Nhap so luong nhan vien: ";
				cin>>n;
				a = new NV[n];
				NhapDSNV(n, a);
                XuatDSNV(n,a);
                delete(a);
                system("pause");
    return 0;
}
