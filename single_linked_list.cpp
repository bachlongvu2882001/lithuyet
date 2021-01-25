#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *pNext;
};
typedef struct node NODE;
struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void KhoiTao(LIST &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
NODE *KhoiTaoNODE(int x){
	NODE *p=new NODE;
	p->data=x;
	p->pNext=NULL;
	return p;
}
void ThemVaoDau(LIST &l, NODE *p){
	if(l.pHead==NULL)
	   l.pHead=l.pTail=p;
	else{
		p->pNext=l.pHead;
		l.pHead=p;
	}
}
void ThemVaoCuoi(LIST &l,NODE *p){
	if(l.pHead==NULL)
	 l.pHead=l.pTail=p;
	else{
	 l.pTail->pNext=p;
	 l.pTail=p;
	 
	}
}
float TimMax(LIST l){
	int max=l.pHead->data;
	for(NODE *k=l.pHead->pNext;k!=NULL;k=k->pNext){
		if(max<k->data)
		max=k->data;
	}
	return max;
}
void XuatDanhSach(LIST l){
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
	cout<<k->data<<" ";
}
int main(){
	LIST l;
	KhoiTao(l);
	int n;
	cout<<"\nNhap so luong node can them ";
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cout<<"\nNhap gia tri so nguyen thu "<<i<<" ";
		cin>>x;
		NODE *p=KhoiTaoNODE(x);
		ThemVaoCuoi(l,p);
	}
	cout<<"\nDanh sach lien ket la ";
	XuatDanhSach(l);
	cout<<"\nGia tri lon nhat la "<<TimMax(l);
	return 0;
}
