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
    int Sochongoi(){
        return this->scn;
    }
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
        float TaiTrong(){
            return this->taitrong;
        }
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
        cout<<"\nNhap xe thu "<<
        i+1<<" : "<<endl;
       (a+i)->Nhap(); 
    }
    cout<<"NHAP XE TAI: "<<endl;
    for(int i=0; i<m; i++){
        cout<<"Nhap xe thu "<<i+1<<" : "<<endl;
        (b+i)->Nhap();
    }
}

void XuatXe(XeCon *a, XeTai *b,int n, int m){
    cout<<"==========XE CON=========== "<<endl;
    for(int i=0; i<n; i++)
    {
       (a+i)->Xuat(); 
       cout<<"\n=========================";
    }
    cout<<"\n===========XE TAI============= "<<endl;
    for(int i=0; i<m; i++){
        (b+i)->Xuat();
    }
}

void Duoi1TanVaKhongQua5ChoNgoi(int n, XeCon *a){
    int temp=0;
for(int i=0; i<n; i++){
if((a+i)->gettl()<1&&(a+i)->Sochongoi()<6){
    (a+i)->XeCon::Xuat();
    temp=1;
    cout<<"\n==============================================\n";
}
}
if(temp==0){
    cout<<"Khong co xe nao thoa man dieu kien"<<endl;
}
}
float TimTaiTrongMin(int m, XeTai *b){
    float min = (b+0)->TaiTrong();
      for(int i=0; i<m; i++){
            if(min>(b+i)->TaiTrong()){
                min = (b+i)->TaiTrong();
          }
      }
      return min;
}

void Hon5TanvaTaiTrongItNhat(int m, XeTai *b){
   float min=TimTaiTrongMin(m,b);
   int temp=0;
      for(int i=0; i<m; i++){
            if(min==(b+i)->TaiTrong()&&(b+i)->gettl()>5){
                (b+i)->Xuat();
                cout<<"\n=============================================";
                   temp=1;
          }
      }
      if(temp==0){
          cout<<"Khong co xe nao thoa man dieu kien"<<endl;
      }
   
}

int main(){
    XeCon *a;
    XeTai *b;
    int m, n;
    do{
        system("cls");
        cout<<"\n================MENU=================";
        cout<<"\n 1.Nhap n xe con va m xe tai.";
        cout<<"\n 2.Xuat danh sach.";
        cout<<"\n 3.Tim xe tai trong luong lon hon 5 tan va co tai trong it nhat.";
        cout<<"\n 4.Tim xe con co trong luong duoi 1 tan va khong qua 5 cho ngoi.";
        cout<<"\n 5.Out game."<<endl;
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
                    Hon5TanvaTaiTrongItNhat(m,b);
                    break;
                    
            case 4:
            Duoi1TanVaKhongQua5ChoNgoi(n,a);
            cout<<"\n==================\n";
                    break;

            case 5:
                    exit(1);
            }
            system("pause");
    }while(1);
    delete a;
    delete b;
    system("pause");
    return 0;
}