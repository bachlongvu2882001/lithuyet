#include<iostream>
using namespace std;
void Nhap(int a[],int &n){
	cout<<"Nhap so phan tu ";
	cin>>n;
	for(int i=0;i<=n-1;i++){
	  cout<<"\nNhap phan tu thu  "<<i+1<<"  ";
	  cin>>a[i];
}
}
void Xuat(int a[],int n){
	for(int i=0;i<=n-1;i++){
		cout<<a[i]<<"   ";
	}
	cout<<endl;
}
void Bubblesort(int a[], int n){
	for(int i=0;i<=n-1;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1])
			swap(a[j],a[j-1]);
		}}
}
void Selecttionsort(int a[], int n){
	for(int i=0;i<=n-2;i++){
		int min=i;
		for(int j=i+1;j<n-1;j++)
			if(a[j]<a[min]) min=j;
			swap(a[min],a[i]);
			}
}
void Insertsort(int a[],int n){
	for(int i=0;i<=n-1;i++){
		int t=a[i+1];
		int j=i-1;
		while((t<a[j])&&j>=0){
			a[j+1]=a[j];
			j--;
		}
		}
}
int main()
{
    int a[100],n;
    Nhap(a,n);
    cout<<"Danh sach truoc khi sap xep"<<endl;
    Xuat(a,n);
    cout<<" Sap xep noi bot"<<endl;
    Bubblesort(a,n);
    Xuat(a,n);
    cout<<"Sap xep chon "<<endl;
    Selecttionsort(a,n);
    Xuat(a,n);
    cout<<"Sap xep chen "<<endl;
    Insertsort(a,n);
    Xuat(a,n);
	return 0;
}
