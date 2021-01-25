#include<iostream>
#include<iomanip>
#include<string>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//TAO CLASS SINH VIEN
class SV{  
    protected:
		string hoten;
		string namsinh;
		string gioitinh;
		string lop;
		int khoa;
		int msv;
		bool loaiSV;
	public:
		virtual void Nhap(); 
		virtual void Xuat(); 
        int getMSV();
		string HOTEN();
		void setLoai(bool l);
		bool getLoai();
		virtual float getTD();
		virtual float DTB();
		virtual float TOAN();
		virtual float LI();
		virtual float HOA();

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CLASS SINH VIEN
///////////////////////////////////////////////////////////////////////////////////////////////////////////
string SV::HOTEN(){
    return this->hoten;
}
/////////////////////////////////////////////////////////////
//NHẬP SINH VIÊN
///////////////////////////////////////////////////////////
 void SV::Nhap()
 {
 	cout<<"\nMa sinh vien: ";
 	cin>>msv;
	cin.ignore();
 	cout<<"\nHo Va Ten: ";
 	getline(cin,hoten);
 	cout<<"\nNgay Thang Nam Sinh: ";
 	getline(cin,namsinh);
 	cout<<"\nGioi tinh: ";
 	getline(cin,gioitinh);
 	
 }
 //XUẤT SINH VIÊN
 //////////////////////////////////////////////////////////////////////////////////////////////////////////
void SV::Xuat()
{
    cout<<"\nMa sinh vien: "<<msv;
 	cout<<"\nHo Va Ten:  "<<hoten;
 	cout<<"\nNgay Thang Nam Sinh:  "<<namsinh;
 	cout<<"\nGioi tinh: "<<gioitinh;
}
//LẤY MÃ SỐ INH VIÊN
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int SV::getMSV(){
    return this->msv;
}
////////////////////////////////////////////////////////////////////////////

void SV::setLoai(bool l){
	loaiSV=l;
}
bool SV::getLoai(){
	return loaiSV;
}
////////////////////////////////////////////////////////
 float SV::getTD(){
	return 0;
}
 float SV::DTB(){
	return 0;
		}
   float SV::TOAN(){
	   return 0;
   }
	float SV::LI(){
	   return 0;
   }
    float SV::HOA(){
	   return 0;
   }
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//CLASS MÔN

class Mon{
	protected:
	  string to_mmh;
	  string l_mmh;
	  string h_mmh;
	  string td_mmh;
	  float toan,li,hoa,td;
	   int to_tclt,l_tclt,h_tclt,td_tclt;
	   int to_tcth,l_tcth,h_tcth,td_tcth;
       
	public:
		Mon();
		~Mon();
	    void Nhap();
	    void Xuat(); 
	    float getTD(){
	  return 0;}
	  float TOAN();
	     float LI();
		 float HOA();
        float DTB(){
	  return 0;
		}  
};
  float Mon::TOAN(){
	   return 0;
   }
	float Mon::LI(){
	   return 0;
   }
    float Mon::HOA(){
	   return 0;
   }
////////////////////////////////////////////////////////////////////////////////////////////////////
    
////////////////////////////////////////////////////////////////////////////////////////////////
//HÀM TẠO 
Mon::Mon(){
	//toan - ma mon - tin chi li thuyet - tin chi thuc hanh
	to_mmh = "TIT1";
	to_tclt = 3;
	to_tcth = 0;
	//li- ma mon - tin chi li thuyet - tin chi thuc hanh
	l_mmh = "LIT1";
	l_tclt = 3;
	l_tcth = 1;
	//Hoa - ma mon - tin chi li thuyet - tin chi thuc hanh
	h_mmh = "HIT1";
	h_tclt = 2;
	h_tcth = 1;	
	//The duc - ma mon - tin chi li thuyet - tin chi thuc hanh
	td_mmh = "TDIT1";
	td_tclt = 0;
	td_tcth = 1;	
}
//HÀM HỦY
Mon::~Mon(){
}
//////////////////////////////////////////////////////////////////////////////////
void Mon::Nhap()
{
	cout<<"\nNhap diem toan = ";
	cin>>toan;
	cout<<"\nNhap diem li = ";
	cin>>li;
    cout<<"\nNhap diem hoa = ";
	cin>>hoa;
	cout<<"\nNhap diem thi the duc= ";
	cin>>td;
}
///////////////////////////////////////////////////////////////////////////
void Mon::Xuat(){
    cout<<"\nMa mon hoc_TOAN: "<<to_mmh;
	cout<<"\nDiem toan=  "<<toan<<" Tin chi li thuyet: "<<to_tclt<<" Tin chi thuc hanh: "<<to_tcth;
	cout<<"\nMa mon hoc_LI: "<<l_mmh;
	cout<<"\nDiem li=  "<<li<<" Tin chi li thuyet: "<<l_tclt<<" Tin chi thuc hanh: "<<l_tcth;
	cout<<"\nMa mon hoc_HOA=  "<<h_mmh;
	cout<<"\nDiem hoa=  "<<hoa<<" Tin chi li thuyet: "<<h_tclt<<" Tin chi thuc hanh: "<<h_tcth;
	cout<<"\nMa mon hoc_THE_DUC=  "<<td_mmh;
	cout<<"\nDiem the duc =  "<<td<<" Tin chi li thuyet: "<<td_tclt<<" Tin chi thuc hanh: "<<td_tcth;
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//////////////////////////////////////////////////////
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//TAO CLASS LOP
class LopCQ:public Mon,public SV{ //lop chinh quy
	protected:
    	string MaLop;
    	string TenLop;
    	int Khoa;
    public:
		LopCQ();
		~LopCQ();
		void Nhap();
        void Xuat();
		void QuanLiMonHoc(int n);
		float getTD();
		float DTB();
		float TOAN();
	     float LI();
		 float HOA();
};
float LopCQ::TOAN(){
	   return this->toan;
   }
	float LopCQ::LI(){
	   return this->li;
   }
    float LopCQ::HOA(){
	   return this->hoa;
   }
float LopCQ::getTD(){
	return this->td;
}
    float LopCQ::DTB(){
	return (toan+li+hoa)/3;
		}  
//////////////////////////////////////////////////////////////////////////////
//Class Lop
LopCQ::LopCQ(){ // LOP CHINH QUY
	this->MaLop = "IT1";
	this->TenLop="Cong Nghe Thong Tin";	
}
LopCQ::~LopCQ(){
}
////////////////////////////////////////////////////////////////////////////////
void LopCQ::Nhap(){
    cout<<"\nKhoa: ";
    cin>>Khoa;
    SV::Nhap();
    Mon::Nhap();
}
////////////////////////////////////////////////////////////////////////////////////
void LopCQ::Xuat(){
    cout<<"\nMa Lop: "<< MaLop << endl <<"Ten Lop: "<<TenLop<<endl<<"Khoa: "<<Khoa<<endl;
    SV::Xuat();
    Mon::Xuat();
	cout<<"\nDiem trung binh cua ban la:  "<<DTB();
}
////////////////////////////////////////////////////////////////////////////////
//QUẢN LÍ MÔN HỌC CÓ LÍ THUYẾT HOẶC CÓ THỰC HÀNH
void LopCQ::QuanLiMonHoc(int n){
	
	if(n==1){
		cout<<"\nMon hoc chi co li thuyet : ";
		cout<<"\nMa mon hoc_TOAN: "<<to_mmh;
		cout<<"\nDiem toan=  "<<toan<<" Tin chi li thuyet: "<<to_tclt<<" Tin chi thuc hanh: "<<to_tcth;
	}
	else if(n==2){
		cout<<"\nMonhoc chi co thuc hanh: ";
		cout<<"\nMa mon hoc_THE_DUC=  "<<td_mmh;
	    cout<<"\nDiem hoa=  "<<td<<" Tin chi li thuyet: "<<td_tclt<<" Tin chi thuc hanh: "<<td_tcth;
}
    else{
		cout<<"\nMon hoc co ca li thuyet va thuc hanh: ";
		cout<<"\nMa mon hoc_LI: "<<l_mmh;
	    cout<<"\nDiem li=  "<<li<<" Tin chi li thuyet: "<<l_tclt<<" Tin chi thuc hanh: "<<l_tcth;
		cout<<"\n==========================================================================";
		cout<<"\nMa mon hoc_HOA=  "<<h_mmh;
	    cout<<"\nDiem hoa=  "<<hoa<<" Tin chi li thuyet: "<<h_tclt<<" Tin chi thuc hanh: "<<h_tcth;
	}
	
}
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//////////////////////////////////////////////////////
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//TẠO CLASS LỚP VỪA HỌC VỪA LÀM
class LopVHVL:public Mon,public SV{ // Lop vua hoc vua lam
	private:
    	string MaLop;
    	string TenLop;
    	int Khoa;

	public:
		LopVHVL();
		~LopVHVL();
		void Nhap();
		void Xuat();
		float getTD(){
	    return this->td;
           }
		float DTB(){
		return ((toan+li+hoa)/3);
		}  
		float TOAN();
	     float LI();
		 float HOA();
};//////////////////////////////////////////////////////////////////////////////
float LopVHVL::TOAN(){
	   return this->toan;
   }
	float LopVHVL::LI(){
	   return this->li;
   }
    float LopVHVL::HOA(){
	   return this->hoa;
   }
//////////////////////////////////////////////////////////////////////////////////
LopVHVL::LopVHVL(){//Lop vua hoc vua lam
	MaLop = "IT2";
	TenLop="Cong Nghe Thong Tin 2";	
}
LopVHVL::~LopVHVL(){
}
////////////////////////////////////////////////////////////////////////////////
void LopVHVL::Nhap(){
	cout<<"\nKhoa: ";
    cin>>Khoa;
    SV::Nhap();
    Mon::Nhap();
}//////////////////////////////////////////////////////////////////////////////
void LopVHVL::Xuat(){
	cout<<"\nMa Lop: "<< MaLop << endl <<"Ten Lop: "<<TenLop<<endl<<"Khoa: "<<Khoa<<endl;
    SV::Xuat();
    Mon::Xuat();
	cout<<"\nDiem trung binh cua ban la:  "<<DTB();
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//////////////////////////////////////////////////////
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//CLASS KE THUA_TONG HOP TAT CA CLASS TREN
class TongHop:public LopCQ,public LopVHVL{
	protected:
			vector <SV *> TH;
    public:
	    float TOAN();
	    float LI();
		float HOA();
	   void Nhap();
	   void Xuat();
	   float getTD();
	   float getDTB();
	   void HocBong();
	   void TimKiemHB();
	   void TimKiemMSSV();
	   void TimKiemTenSV();
	   void SapXep();
	   void Xoa();
};
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
/////////////////////////////////////////////////
//TẠO SWITCH CASE LỰA CHỌN
void TongHop::Nhap(){
	int k,u;
	SV *a;
   do{
	system("cls");
	cout<<"\n*******************************************************";
    cout<<"\n*            HE THONG QUAN LY SINH VIEN               *";
    cout<<"\n*                                                     *";
	cout<<"\n*  1.NHAP VAO THONG TIN SINH VIEN                     *";
	cout<<"\n*                                                     *";
    cout<<"\n*  2.QUAN LI MON HOC                                  *";
    cout<<"\n*                                                     *";
    cout<<"\n*  3.QUAN LY SINH VIEN                                *";
    cout<<"\n*                                                     *";
    cout<<"\n*  4.QUAN LY DIEM                                     *";
    cout<<"\n*                                                     *";
    cout<<"\n*  5.QUAN LY HOC BONG                                 *";
	cout<<"\n*                                                     *";
	cout<<"\n*  6.THOAT                                            *";
    cout<<"\n*                                                     *";
    cout<<"\n*******************************************************";
    cout<<"\nNHAP LUA CHON CUA BAN: ";
    cin>>k;
    switch(k){
	case 1: 
			{int i=1;
			while(i){
				system("cls");
				cout<<"\n1. Nhap sinh vien chinh quy"<<endl;
				cout<<"2. Nhap sinh vien vua hoc vua lam"<<endl;
				cout<<"3. Thoat nhap"<<endl;
				cout<<"Moi lua chon: ";
				cin>>u;
				system("cls");
			switch(u){
					case 1:
						a=new LopCQ;
						a->Nhap();
						TH.push_back(a);
						a->setLoai(true);
						break;
					case 2:
						a=new LopVHVL;
						a->Nhap();
						TH.push_back(a);
						a->setLoai(false);
						break;
					case 3:
						i=0;
						break;
					default:
						cout<<"Nhap sai. Moi nhap lai"<<endl;
				}
			}}
			break;
    case 2:
		     do{
		     system("cls");
    		 cout<<"\n*******************************************************";
    		 cout<<"\n*              QUAN LI MON HOC                         *";
    		 cout<<"\n*                                                      *";
    		 cout<<"\n*   1. Hien thi mon hoc chi co li thuyet               *";
			 cout<<"\n*   2. Hien thi mon hoc chi co thuc hanh               *";
			 cout<<"\n*   3. Hien thi mon hoc ca ca li thuyet va thuc hanh   *";
			 cout<<"\n*   4. Quay lai                                        *";
			 cout<<"\n*                                                      *";
             cout<<"\n*******************************************************";
             cout<<"\nNhap vao lua chon cua ban: ";
             cin>>u;
             system("cls");
           switch(u){
           	case 1:
           		LopCQ::QuanLiMonHoc(u);
				cin.get();
				break;		
           	case 2:
           		LopCQ::QuanLiMonHoc(u);
				cin.get();
           		break;
           	case 3:
           		LopCQ::QuanLiMonHoc(u);
           		cin.get();
           		break;
           	case 4:
				 break;}
			cout << endl;
			cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
			cin.get();	 	 
			}while(u!=4);
			 break;
	case 3:
	        do{
			 system("cls");
			 cout<<"\n*******************************************************";
			 cout<<"\n*                                                     *";
		     cout<<"\n*              QUAN LY SINH VIEN                      *";
		     cout<<"\n*                                                     *";
		     cout<<"\n*  1. Tim kiem theo ma so sinh vien                   *";
		     cout<<"\n*  2. Tim kiem theo ten sinh vien                     *";
		     cout<<"\n*  3. Danh sach sinh vien                             *";
		     cout<<"\n*  4. Xoa                                             *";
		     cout<<"\n*  5. Quay lai                                        *";
		     cout<<"\n*                                                     *";
		     cout<<"\n*******************************************************";
		     cout<<"\nNhap vao lua chon cua ban  ";
		     cin>>u;
		     system("cls");
		     switch(u){
		     	case 1:
		     		TimKiemMSSV();                 
		     		cin.get();
		     		break;
		     	case 2:
		     		TimKiemTenSV();
		     		cin.get();
		     		break;
		     	case 3:
		     		Xuat();
		     		cin.get();
		     		break;
		     	case 4:
		     		Xoa();
		     		cin.get();
		     		break;
		     	case 5:
		     		break;
			 } 
			 cout << endl;
			cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
			cin.get();
			}while(u!=5);
			break;
	case 4: // chuc nang ben trong quan ly diem
	       do{
			system("cls");
			cout<<"\n*******************************************************";
		    cout<<"\n*                QUAN LY DIEM                         *";
		    cout<<"\n*                                                     *";
		    cout<<"\n*  1. Danh sach SV theo thu tu giam dan cua DTB       *";
		    cout<<"\n*  2. Tra cuu ket qua hoc tap cua sinh vien           *";
		    cout<<"\n*  3. Xoa                                             *";
		    cout<<"\n*  4. Quay lai                                        *";
		    cout<<"\n*******************************************************";
		    cout<<"\nNhap vao lua chon cua ban:  ";
		    cin>>u;
		    system("cls");
		    switch(u){
		        case 1:
		        	SapXep();
		        	cin.get();
		        	break;
		        case 2:
		        	TimKiemMSSV();      
		        	cin.get();
		        	break;
		        case 3:
		        	Xoa();
		        	cin.get();
		        case 4:
		           break;}
				cout << endl;
			  	cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
				cin.get();
			    }while(u!=5);
			    break;
	case 5: // chuc nang ben trong quan ly hoc bong
	        do{
			 system("cls");
			 cout<<"\n*******************************************************";
			 cout<<"\n*             QUAN LY HOC BONG                        *";
		     cout<<"\n*                                                     *";
		     cout<<"\n*  1. Danh sach hoc bong                              *";
		     cout<<"\n*  2. Tim sinh vien trong danh sach hoc bong          *";
		     cout<<"\n*  3. Quay lai                                        *";
		     cout<<"\n*                                                     *";
		     cout<<"\n*******************************************************";
		     cout<<"\nNhap vao lua chon cua ban: ";
		     cin>>u;
		     system("cls");
		     switch(u){
		     	case 1: 
					  HocBong();     
		     	     cin.get();
		     	     break;
		        case 2:
		     	     TimKiemHB();
		     	     cin.get();
		     	     break;
		     	case 3:
		     		 break;} 
	        	 cout << endl;
			  	cout << setfill(' ') << setw(6) << ' ' << "Enter de quay lai";
				cin.get();
			 }while(u!=3);
			 break;
	case 6:// thong chuong trinh
		     exit(1);
}}while(1);
}
//XÓA VỊ TRÍ MÀ BẠN MUỐN XÓA THEO MÃ SỐ SINH VIÊN
void TongHop::Xoa(){
    int vitri=0,a=0;
	double b;
	cout<<"\nNhap ma so sinh vien cua ban:  ";
	cin>>b;
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			 if(TH[i]->getMSV()==b){
				vitri=i;
				a++;
				cout<<"\n================================";
				}
				
		    }
		else{
			if(TH[i]->getLoai()==false && (TH[i]->getMSV()==b)){
				vitri=i;
				a++;
				cout<<"\n================================";
				}
		}
      }
	  if(a==0)
	  {
	  cout<<"\nKhong co sinh vien can xoa";
	  }
	  if(a!=0){
      TH.erase(TH.begin()+vitri);
	  cout<<"\nXoa thanh cong";
	  }
	 
}
//////////////////////////////////////////////////////
//SẮP XẾP THEO ĐIỂM TRUNG BÌNH GIẢM DẦN
void TongHop::SapXep(){
	for(int i=0;i<TH.size();i++){ // thuat toan sap xep noi bot
		for(int j=i+1;j<TH.size();j++){
			if(TH[i]->DTB() < TH[j]->DTB() && TH[i]->DTB() != TH [j]->DTB()){
				swap(TH[i],TH[j]);
			}
		}
	}
	Xuat();
}
//////////////////////////////////////////////////////
/////////////////////////////////////////////////
//TÌM KIẾM THEO TÊN SINH VIÊN
void TongHop::TimKiemTenSV(){
    int a = 0;
	string b;
	cout<<"\nNhap ten sinh vien cua ban:  ";
	cin.ignore(1);
	getline(cin,b);
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			 if(TH[i]->HOTEN()==b){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				TH[i]->Xuat();
				if(TH[i]->DTB()>=8 && TH[i]->getTD()>=6.5 && TH[i]->HOA()>=6.5 && TH[i]->TOAN()>=6.5 && TH[i]->LI()>=6.5)
						  {cout<<"\nHoc luc gioi";}
						else if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && TH[i]->HOA()>=5 && TH[i]->TOAN()>=5 && TH[i]->LI()>=5){
							cout<<"\nHoc luc kha";
						}
						else if(TH[i]->DTB()>=5 && TH[i]->getTD()>=3.5 && TH[i]->HOA()>=3.5 && TH[i]->TOAN()>=3.5 && TH[i]->LI()>=3.5){
							cout<<"\nHoc luc trung binh";
						}
						else
						{
							cout<<"\nHoc luc yeu";
						}
				a++;
				cout<<"\n================================";
				}
				
		    }
		else{
			if(TH[i]->getLoai()==false && (TH[i]->HOTEN()==b)){
				cout<<"\nSinh vien he vua hoc vua lam: "<<endl;
				TH[i]->Xuat();
				if(TH[i]->DTB()>=8 && TH[i]->getTD()>=6.5 && TH[i]->HOA()>=6.5 && TH[i]->TOAN()>=6.5 && TH[i]->LI()>=6.5)
						  {cout<<"\nHoc luc gioi";}
						else if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && TH[i]->HOA()>=5 && TH[i]->TOAN()>=5 && TH[i]->LI()>=5){
							cout<<"\nHoc luc kha";
						}
						else if(TH[i]->DTB()>=5 && TH[i]->getTD()>=3.5 && TH[i]->HOA()>=3.5 && TH[i]->TOAN()>=3.5 && TH[i]->LI()>=3.5){
							cout<<"\nHoc luc trung binh";
						}
						else
						{
							cout<<"\nHoc luc yeu";
						}
				a++;
				cout<<"\n================================";
				}
		}
	}
	if(a==0){
		cout<<"\nKhong co ten sinh vien ban can tim";
	}
}
//////////////////////////////////////////////////////
/////////////////////////////////////////////////
//TÌM KIẾM THEO MÃ SỐ SINH VIEN
 void TongHop::TimKiemMSSV(){
      int a = 0;
	double b;
	cout<<"\nNhap ma so sinh vien cua ban:  ";
	cin>>b;
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			 if(TH[i]->getMSV()==b){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				TH[i]->Xuat();
						if(TH[i]->DTB()>=8 && TH[i]->getTD()>=6.5 && TH[i]->HOA()>=6.5 && TH[i]->TOAN()>=6.5 && TH[i]->LI()>=6.5)
						  {cout<<"\nHoc luc gioi";}
						else if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && TH[i]->HOA()>=5 && TH[i]->TOAN()>=5 && TH[i]->LI()>=5){
							cout<<"\nHoc luc kha";
						}
						else if(TH[i]->DTB()>=5 && TH[i]->getTD()>=3.5 && TH[i]->HOA()>=3.5 && TH[i]->TOAN()>=3.5 && TH[i]->LI()>=3.5){
							cout<<"\nHoc luc trung binh";
						}
						else
						{
							cout<<"\nHoc luc yeu";
						}
						
				a++;
				cout<<"\n================================";
				}
				
		    }
		else{
			if(TH[i]->getLoai()==false && (TH[i]->getMSV()==b)){
				cout<<"\nSinh vien he vua hoc vua lam: "<<endl;
				TH[i]->Xuat();
						if(TH[i]->DTB()>=8 && TH[i]->getTD()>=6.5 && TH[i]->HOA()>=6.5 && TH[i]->TOAN()>=6.5 && TH[i]->LI()>=6.5)
								{cout<<"\nHoc luc gioi";}
								else if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && TH[i]->HOA()>=5 && TH[i]->TOAN()>=5 && TH[i]->LI()>=5){
									cout<<"\nHoc luc kha";
								}
								else if(TH[i]->DTB()>=5 && TH[i]->getTD()>=3.5 && TH[i]->HOA()>=3.5 && TH[i]->TOAN()>=3.5 && TH[i]->LI()>=3.5){
									cout<<"\nHoc luc trung binh";
								}
								else
								{
									cout<<"\nHoc luc yeu";
								}
				a++;
				cout<<"\n================================";
				}
		}
	}
	if(a==0){
		cout<<"\nKhong co MSSV  ban can tim";
	}
 }
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//DANH SÁCH SINH VIÊN CÓ TRONG HỌC BỔNG
void TongHop::HocBong(){
	int a = 0;
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			 if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
				
		    }
		else{
			if(TH[i]->getLoai()==false&&TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5){
				cout<<"\nSinh vien he vua hoc vua lam: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
		}
	}
	if(a==0){
		cout<<"\nKhong co sinh vien nao co hoc bong";
	}
	}
	//////////////////////////////////////////////////////
/////////////////////////////////////////////////
//TÌM KIẾM SINH VIÊN CÓ TRONG HỌC BỔNG KHÔNG. THEO MSSV
void TongHop::TimKiemHB(){
	int a = 0;
	double b;
	cout<<"\nNhap ma so sinh vien cua ban:  ";
	cin>>b;
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			 if(TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && (TH[i]->getMSV()==b)){
				cout<<"\nSinh vien he chinh quy: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
				
		    }
		else{
			if(TH[i]->getLoai()==false && TH[i]->DTB()>=6.5 && TH[i]->getTD()>=5 && (TH[i]->getMSV()==b)){
				cout<<"\nSinh vien he vua hoc vua lam: "<<endl;
				TH[i]->Xuat();
				a++;
				cout<<"\n================================";
				}
		}
	}
	if(a==0){
		cout<<"\nKhong co sinh vien nao co hoc bong";
	}
	}
//////////////////////////////////////////////////////
/////////////////////////////////////////////////		                
void TongHop::Xuat(){
	for(int i=0;i<TH.size();i++){
		if(TH[i]->getLoai()==true){
			cout<<"\nSinh vien he chinh quy: "<<endl;
			TH[i]->Xuat();
			cout<<"\n================================";
		}
		else{
			cout<<"\nSinh vien he vua hoc vua lam: "<<endl;
			TH[i]->Xuat();
			cout<<"\n================================";
		}
	}
}
//////////////////////////////////////////////////////
/////////////////////////////////////////////////
float TongHop::getTD(){
	return 0;
}
    float DTB(){
	return 0;
		}  
//////////////////////////////////////////////////////
/////////////////////////////////////////////////	
 float TongHop::TOAN(){
	   return 0;
   }
	float TongHop::LI(){
	   return 0;
   }
    float TongHop::HOA(){
	   return 0;
   }
   //////////////////////////////////////////////////////
/////////////////////////////////////////////////	
int main(){
    TongHop *a=new TongHop;
    a->Nhap();
    delete a;
    system("pause");
    return 0;
}
