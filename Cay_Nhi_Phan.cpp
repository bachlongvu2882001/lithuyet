#include<iostream>
using namespace std;
typedef struct tagnode 
{
	int data;
	struct tagnode *pleft;// nh�nh b�n tr�i
	struct tagnode *pright;//nh�nh b�n ph?i
}tNode;

typedef struct tagtree
{ 
	tNode *root;
}TREE;// khai b�o 1 c�y (TREE) c� ki?u d? li?u l� tNode

void init(TREE &t)
{
	t.root=NULL;
} // kh?i t?o c�y NULL

tNode *Createnode(int data)
{
	tNode *p;
	p=new tNode;
	if(p!=NULL)
	{	
		p->data=data;
		p->pleft=NULL;
		p->pright=NULL;
	}
	return p;
}// h�m t?o 1 node

void insert(tNode *&r,int data)
{

	if(r==NULL)
		r=Createnode(data);
	else
		if(r->data>data)
			insert(r->pleft,data);
		else
			insert(r->pright,data);
}// th�m 1 node v�o c�y, n?u nh? hon th� b�n tr�i, l?n hon th� b�n ph?i, d? li?u l� s? nguy�n data

void insert1(TREE &t,int data)
{
	insert(t.root,data);
}

void print(tNode *r)
{
	if(r==NULL)
		return;
	
	print(r->pleft);
	printf("%4d",r->data);
	print(r->pright);
}// h�m in danh s�ch c�y

void print(TREE t)
{
	print(t.root);
}// in c? c�y nh? ph�n
void timthemang(tNode *&p,tNode *&q)
{
	if(q->pleft!=NULL)
		timthemang(p,q->pleft);
	else
	{
		p->data=q->data;
		
		p=q;
		q=q->pright;
	}
}// h�m t�m 1 node tr�n c�y

int del(tNode *&p,int data)
{
	if(p==NULL)
		return 0;
	if(p->data>data)
		del(p->pleft,data);
	if(p->data.pright,data);
	if(p->data==data)
	{
		tNode *p1=p;
		if(p->pleft==NULL)
			p=p->pright;
		else
			if(p->pright==NULL)
				p=p->pleft;
			else
			{
		tNode *q=p->pright;
		timthemang(p1,q);
			}
			delete p1;
	}
	return 0;
}// h�m x�a 1 node tr�n c�y

void demnode(tNode *p,int &dem)
{
	
	if(p==NULL)
		return ;
	demnode(p->pleft,dem);
	dem++;
	demnode(p->pright,dem);
	
		
}// h�m d?m node tr�n c�y, v?i bi?n dem l� tham bi?n

int demnode1(tNode *t)
{
	if(t==NULL)
		return 0;
	int x=demnode1(t->pleft);
	int y=demnode1(t->pright);
	/* if(r->pleft==NULL&&r->pright==NULL)
	return 1;
	return(x+y);
	*/
	return x+y+1;
}//h�m d?m node tr�n c�y, v?i k�t qu? tr? v? l� s? lu?ng node tr�n c�y

void demla(tNode *t,int &dem)
{
	if(t==NULL)
		return;
	if(t->pleft==NULL)
		if(t->pright==NULL)
			dem++;

	demla(t->pleft,dem);
	
	demla(t->pright,dem);
	
	
}// d?m n�t l�, v� n�t cu?i c�ng ? c�c nh�nh

void docaonode(tNode *t,int data,int &dem)
{
	if(t->data>data)
	{   
		docaonode(t->pleft,data,dem);
		
	}
	else
		if(t->datapright,data,dem);
			
		}
		else
		{
			
			return;
		}
			dem++;
}// h�m d?m d? cao c?a c�y, t?c l� nh�nh c� nhi?u n�t nh?t

//tim kiem
tNode* timnode(tNode *t,int data)
{
	if(t)
	{
		if(t->data==data)
			return t;
		if(t->data>data)
			return timnode(t->pleft,data);
		else
			return timnode(t->pright,data);
	}
	return NULL;

}// h�m t�m ki?m 1 data cho tru?c, k�t qu? null l� kh�ng t�m th?y, ngu?c l?i s? tr? v? node d�

int tinhchieucaonut(tNode *r)
{
	if(r==NULL)
		return 0;
	if(r->pleft==NULL&&r->pright==NULL)
		return 0;
	int h1=tinhchieucaonut(r->pleft);
	int h2=tinhchieucaonut(r->pright);
	return 1+(h1>h2?h1:h2);
}// t�nh chi?u cao c?a c�y

// h�m ch�nh d? g?i c�c h�m c?n ch?y
void main()
{

	TREE t;
	init(t);
	int n,data,dem=0;
	cout<<"nhap so luong";
	cin>>n;
	for(int i=0;iscanf("%d",&data);
		insert1(t,data);
	}
	cout<<"\nCay :");
	cin>>t;
	//printf("Nhap phan tu can xoa");
	//scanf("%d",&data);
	//del(t.root,data);
	//*print*/print(t);
	demnode(t.root,dem);
	//dem=demnode1(t.root);
	cout<<"\nco tat ca co: %d"<<dem;
	dem=0;
	demla(t.root,dem);
	
	cout<<"\nnut la %d"<<dem;
	dem=0;
	cout<<"\nNhap phan tu can dem do cao";
	cin>>data; 
	docaonode(t.root,data,dem);
	cout<<data<<dem;
	dem=0;
	//docaocay(t.root,dem);
	dem=tinhchieucaonut(t.root);
	cout<<"\ndo cao cay la "<<dem;
	
	system("pause");
}
