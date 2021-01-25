#include<iostream>
#include<string>
using namespace std;

class Xe{
        string bienso;
        float trongluong;
    public:
        void Nhap();
        void Xuat();
       
};
void Xe::Nhap(){
    cout<<"\nNhap bien so xe =  ";
    cin.ignore(1);
    getline(cin,bienso);
    cout<<"\nNhap trong luong =  ";
    cin>>trongluong;
}
void Xe::Xuat(){
    cout<<"\nBien so xe =  "<<bienso;
    cout<<"\nTrong luong =  "<<trongluong;
}
class XeCon: public Xe{
   int  scn;
   public:
    void Nhap();
    void Xuat();
    
};
void XeCon::Nhap(){
    Xe::Nhap();
    cout<<"\nNhap so cho ngoi =  ";
   cin>>scn;
    
}
void XeCon::Xuat(){
    Xe::Xuat();
    cout<<"\nSo cho ngoi =  "<<scn;
    
    }
class XeTai: public Xe{
    float taitrong;
    public:
        void Nhap();
        void Xuat();
        
};

void XeTai::Nhap(){
    Xe::Nhap();
     cout<<"\nNhap tai trong cua xa tai =  ";
     cin>>taitrong;

}
void XeTai::Xuat(){
    Xe::Xuat();
        cout<<"\nTai trong cua xe la =  "<<taitrong;
}
void Nhapxe(XeCon *a, XeTai *b,int n,int m){
    
    cout<<"\nNHAP XE CON ";
    for(int i=0; i<n; i++)
    {   
        cout<<"\nNhap xe thu "<< i+1<<" : "<<endl;
       (a+i)->Nhap(); 
    }
    // cout<<"NHAP XE TAI: "<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<"Nhap xe thu "<<i+1<<" : "<<endl;
    //     (b+i)->Nhap();
    // }
}

void XuatXe(XeCon *a, XeTai *b,int &n, int &m){
    cout<<"==========XE CON=========== "<<endl;
    for(int i=0; i<n; i++)
    {
       (a+i)->Xuat(); 
       cout<<"\n=========================";
    }
//     cout<<"\n===========XE TAI============= "<<endl;
//     for(int i=0; i<m; i++){
//         (b+i)->Xuat();
//     }
}
int main(){
	int m, n;
	 cout<<"\nNhap so luong xe con va xe tai =  ";
                    cin>>n>>m;
    XeCon *a=new XeCon[n];
        XeTai            *b=new XeTai[m];
     
    
                    
                    Nhapxe(a,b,n,m);
	system("pause");
	return 0;
	}