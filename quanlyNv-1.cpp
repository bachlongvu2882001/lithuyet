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
        NV();
        NV(string MaNV, string hoten, int ns, string phongban, double luong);
        ~NV();
        friend ostream &operator<<(ostream &os, NV &nv);
        friend istream &operator>>(istream &is, NV &nv);
        bool operator < (NV nv);
        bool operator > (NV nv);
        bool operator == (NV nv);
        double get(double luong);
        int get(int nam);
};

NV::NV(){
    this-> MaNV = "";
    this->hoten ="";
    this->ns = 0;
    this->luong = 0;
}

NV::NV(string MaNV, string hoten, int ns, string phongban, double luong){
    this->MaNV = MaNV;
    this->hoten = hoten;
    this->ns = ns;
    this->phongban = phongban;
    this->luong = luong; 
}
NV::~NV(){}

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
bool NV::operator<(NV nv){
	
	 return (this->luong > nv.luong?1:0);
}
bool NV::operator>(NV nv){
	
	 return (this->luong > nv.luong?0:1);
}
bool NV::operator==(NV nv){
	
	 return (this->luong == nv.luong?1:0);
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
        cout<<*(nv+i);// gọi toán tử xuất
    }
    
    
}
double NV::get(double){
    return this->luong;
}
int NV::get(int ){
    return this->ns;
}
void swap(NV *a,NV *b)
{
	NV c=*a;
	*a = *b;
	*b = c;
}

int partition (NV* nv, int low, int high, int xd)
{   int i;
    if(xd == 0)
    float(i); 
    int pivot = (nv + high)->get(i);    
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && (nv +left)->get(i) < pivot) left++;
        while(right >= left && (nv + right)->get(i) > pivot) right--;
        if (left >= right) break;
        swap((nv + left), (nv + right));
        left++; 
        right--;
    }
    swap((nv + left), (nv + high));
    return left;
}
 

void quickSort(NV *nv, int low, int high, int xd)
{
    if (low < high)
    {
        
        int pi = partition(nv , low, high, xd);
       
        quickSort(nv, low, pi - 1, xd);
        quickSort(nv, pi + 1, high, xd);
    }
    
}
//Ham sap xep diem trung binh theo diem giam dan
//xac dinh kieu du lieu, can sap xep theo nam hay theo luong 
void Sapxepluong(int n,NV *nv)
{   int xd = 0;
	quickSort(nv, n-1, 0, xd);

	XuatDSNV(n , nv);
    
}
void Sapxepns(int n, NV *nv){
    int xd = 1;
    quickSort(nv, 0, n-1, xd);
    XuatDSNV(n, nv);
}

void thongke(int n, NV *nv){
    int c = 0;

    for(int i =0; i<n; i++){
        double j;// nhan biet loai ham can tim
        double l = (nv+i)->get(j);
        if( l >= 10e6){
            c++;
        }

    }
    cout<<"So luong nhan vien co muc luong tren 10tr: "<<c;
}
int main(){
    NV *a;
    int n, k;
    // n = 3;
    // a = new NV[n];
    // NhapDSNV(n, a);
    // if(*(a+1) == *(a))
    // cout<<"Muc luong bang nhau";
    // else 
    // cout<<"muc luong khac nhau";

    // if(*(a+1)<*(a))//goi toan tu so sanh, lay gia tri cua con tro de so sanh
    // cout<<"Thu nhat nho hon thu 2";
    // else 
    // cout<<"thu hai nho hon thu nhat.";

  
    
    
    while(1){
        cout<<endl;
        for(int i=0; i<30; i++)
            cout<<"-|";
        cout<<"-";
        cout<<endl;
		cout<<"Lua chon chuc nang"<<endl;
		cout<<"1. Nhap danh sach nhan vien"<<endl;
		cout<<"2. Xuat danh sach"<<endl;
		cout<<"3. Sap xep tang dan theo luong"<<endl;
        cout<<"4. Sap xep tang dan theo nam sinh"<<endl;
		cout<<"5. Thong ke luong nhan vien co muc luong tren 10tr."<<endl;
        cout<<"6. Thoat."<<endl;
		cin>>k;
		switch(k){
			case 1:
				cout<<"Nhap so luong nhan vien: ";
				cin>>n;
				a = new NV[n];
				NhapDSNV(n, a);
				break;
			case 2:
				XuatDSNV(n,a);
				break;
			case 3:
				Sapxepluong(n, a);
				break;
            case 4: 
                Sapxepns(n, a);
                break;
			case 5:
                thongke(n, a);
                break;
            case 6:
                
				exit(0);
			}
			
    }
    
    delete(a);
    return 0;
}