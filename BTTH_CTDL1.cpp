#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
class Nhanvien{
	private:
		string Ten;
		int Luong;
	public:
	friend class  node;
	friend class LinkedList;
	Nhanvien(){
		Ten="a";
		Luong =0;
	}
	~Nhanvien(){
	}
	void Nhap(){
		cout<<"nhap ten nhan vien vao: ";
		fflush(stdin);
		getline(cin,Ten);
		cout<<"Nhap luong nhan vien vao: ";
		cin>>Luong;
	}
	void Xuat(){
	cout<<"Ten nhan vien: "<<Ten<<endl<<"Luong thang: "<<Luong<<endl;
	}
	int getLuong(){
		return (this->Luong);
	}
};
class  node{
	private:
    Nhanvien a;
    node *next;
    public:
    friend class LinkedList;
 };
class LinkedList{
	private: 
	node *head;
	public:
node *CreateNode(Nhanvien a){
	a.Nhap();
    node *temp; 
    temp = new node; 
    temp->next = NULL;
    temp->a = a; 
    return temp;
}
 //Them cuoi
void AddTail(Nhanvien a){
    node *temp,*p;
    temp = CreateNode(a);
    if(head == NULL){
        head = temp; 
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}
 //Them dau
void  AddHead(Nhanvien a){
    node *temp = CreateNode(a); 
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head; 
        head = temp; 
    }
}
//Them o vi tri bat ki
void  AddAt(Nhanvien a, int position){
    if(position == 0 || head == NULL){
        AddHead(a); 
    }else{
        int k = 1;
        node *p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            AddTail(a);
        }else{
            node *temp = CreateNode(a);
            temp->next = p->next;
            p->next = temp;
        }
    }
}
//Xoa dau
void DelHead(){
    if(head == NULL){
        cout<<"\nDanh sach rong";
    }else{
        head = head->next;
    }
}
//Xoa cuoi
void  DelTail(){
    if (head == NULL || head->next == NULL){
        cout<<"Danh sach rong";
    }
    node *p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next;
}
 //Xoa vi tri bat ki
void  DelAt(int position){
    if(position == 0 || head == NULL || head->next == NULL){
       cout<<"Danh sach rong";
    }else{
        int k = 1;
        node *p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            DelTail();
        }else{
            p->next = p->next->next;
        }
    }
}
//Tim kiem
void Search(){
	Nhanvien max;
	node *p=head;
	max=p->a;
    for(p = head; p != NULL; p = p->next){
    	Nhanvien b=p->a;
        if(b.getLuong() > max.getLuong()){
            max=b;
        }
    }
   cout<<"Nhan vien luong cao nhat la: "<<endl;
   max.Xuat();
}
//Duyet danh sach
void Traverser(){
    cout<<"\n";
    for(node *p = head; p != NULL; p = p->next){
    	Nhanvien b;
		b=p->a;
		b.Xuat();
    }
}
//khoi tao node head
node *InitHead(){
    head = NULL;
    return head;
}
//tra so luong
int Length(){
    int length = 0;
    for(node *p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
//Nhap
void Input(){
    head = InitHead();
    Nhanvien a;
    int n;
    cout<<"Nhap so luong nhan vien vao:";
    cin>>n;
    for(int i = 0; i < n; i++){
        AddTail(a);
    }
}	
};
void Menu(LinkedList a,int &t){
	int c;
	system("cls");
   while (1)
   {
   		cout<<"Chuong trinh quan li nhan vien"<<endl;
      cout<<"1.Nhap"<<endl;
      cout<<"2.Xuat"<<endl;
      cout<<"3.Them dau danh sach"<<endl;
	  cout<<"4.Them cuoi danh sach "<<endl;
	  cout<<"5.Them vi tri bat ki danh sach "<<endl;
      cout<<"6.Xoa bat ki rong danh sach"<<endl;
      cout<<"7.Tim Nhan vien luong cao mhat"<<endl;
      cout<<"8.Thoat"<<endl;
      cout<<"Nhap su lua chon: ";
      cin>>c;
      switch(c) {
         case 1:
         		a.Input();
         	t=1;
            getch();
            return Menu(a,t);
         case 2:
         	if(t==1){
         	a.Traverser();
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 3:
         	if(t==1){
         		Nhanvien b;
         	 a.AddHead(b);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 4:
         	if(t==1){
         	Nhanvien b;
         	a.AddTail(b);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 5:
         	if(t==1){
         	int i;
         	cout<<"Nhap vi tri can them: ";
         	cin>>i;
         	Nhanvien b;
         	a.AddAt(b,i);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 6:
         	if(t==1){
         	int i;
         	cout<<"Nhap vi tri can xoa: ";
         	cin>>i;
         	a.DelAt(i);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 7:
         	if(t==1){
			a.Search();
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 8:
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
}
int main(){
	LinkedList a;
	int t=0;
	Menu(a,t);
}
