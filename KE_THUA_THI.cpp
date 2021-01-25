/* 
Xây dựng lớp xe gồm biển số và trọng lượng
tải trọng là cân nặng của hàng hóa
trọng lượng là cân nặng xe
xe con: số chỗ ngồi
xe tải: tải trọng
a== nhập n xe con m xe tải
b==tìm xe con có trọng lượng nhỏ nhất
c==tìm xe tải có trọng lượng = 5 tấn
d==tìm xe con có số chỗ ngồi là 7*/
#include<iostream>
#include<string>
using namespace std;

class Xe{
        string bienso;
        float trongluong;
    public:
        void Nhap();
        void Xuat();
        float gettl();
};
float Xe::gettl(){
    return this->trongluong;
}
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
    friend void min(int n, XeCon *a);
    void kt(int n, XeCon *a);
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
void min(int n, XeCon *a){
   /* float min = (a+0)->gettl();
    for(int i=0; i<n-1; i++)
            if(min<(a+i)->gettl() ){
                min = (a+0)->gettl();
            
        }
        else{
            min = (a+i)->gettl();
        }*/
   float min = (a+0)->gettl();
   int temp=0;
      for(int i=0; i<n; i++){
            if(min>(a+i)->gettl() ){
                min = (a+i)->gettl();
            temp=i;
            }

      }
(a+temp)->Xuat();
cout<<endl;
}
class XeTai: public Xe{
    float taitrong;
    public:
        void Nhap();
        void Xuat();
        void KT(int n, XeTai *b);
};
void XeTai::KT(int n, XeTai *b){
   cout<<"\nXE TAI 5 TAN ";
    for(int i=0; i<n; i++){
        if((b+i)->taitrong == 5){
            (b+i)->Xuat();
            cout<<"\n==========================";
        }
    }
}
void XeCon::kt(int n, XeCon *a){
    cout<<"Xe con 7 cho "<<endl;
    for(int i=0; i<n; i++){
        if((a+i)->scn ==7){
            (a+i)->Xuat();
             cout<<"\n==========================";
        }
    }
}
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
        cout<<"\nNhap xe thu "<<
        i+1<<" : "<<endl;
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
    XeCon *a;
    XeTai *b;
    int m, n;
    do{
         system("cls");
        cout<<"\n================MENU=================";
        cout<<"\n 1.Nhap so luong xe.";
        cout<<"\n 2.Xuat danh sach.";
        cout<<"\n 3.Tim xe con co trong luong nho nhat.";
        cout<<"\n 4.Tim xe tai trong tai bang 5 tan.";
        cout<<"\n 5.Tim xe con co so cho ngoi bang 7.";
        cout<<"\n 6.Out game."<<endl;
         cout<<"\n Nhap su lua chon =  ";
        int c;
        cin>>c;
       
        switch(c){
            case 1:
                    cout<<"\nNhap so luong xe con va xe tai =  ";
                    cin>>n>>m;
                    a=new XeCon[n];
                    b=new XeTai[m];
                    Nhapxe(a,b,n,m);
                    break;

            case 2:
                    XuatXe(a,b,n,m);
                    break;

            case 3:
                    min(n,a);
                    break;
                    
            case 4:
                    b->KT(n,b);
                    break;
            
            case 5:
                    a->kt(n, a);
                    break;

            case 6:
                    exit(1);
            }
            system("pause");
    }while(1);
    system("pause");
    return 0;
}