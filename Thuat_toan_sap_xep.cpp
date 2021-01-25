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
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
 
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
 
int main()
{
    int a[15],n;
    int arr_size = sizeof(a)/sizeof(a[1]);
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
    cout<<"Sap xep tron "<<endl;
    mergeSort(a, 0, arr_size - 1);
    Xuat(a,n);
	return 0;
}
