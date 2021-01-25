#include<iostream>
using namespace std;
void nhapmang(int a[], int &n)
{ cout<<"nhap so phan tu :" ;
  cin>>n;
  for(int i=0;i<n;i++)
  { cout<<" phan tu thu :"<<i<<"\t";
    cin>>a[i];
  }
}
int xuatmang(int a[],int n)
 {for(int i=0;i<n;i++)
   {
     cout<<a[i]<<"\t";
   }
   cout<<endl<<endl;
 }
void gop(int a[],int n,int b[],int m,int c[],int &p)
{
 p=n+m; 
 for(int i=0;i<p;i++)
  {
   if(i<n) 
     c[i]=a[i];
   else c[i]=b[i-n];  
  }
}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
 
// Hàm sắp xếp bubble sort
void bubbleSort(int c[], int p,int n, int m)
{
    int i, j;
    p=n+m;
    for (i = 0; i < p-1; i++){
        for (j = 0; j < p-i-1; j++){
            if (c[j] > c[j+1]){
                swap(c[j], c[j+1]);
            }
        }
    }
}
//Sắp xếp chọn
void selectionSort(int c[], int p,int n,int m)
{
  p=n+m;
    int i, j, min_idx;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 0; i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
    min_idx = i;
    for (j = i+1; j < n; j++)
        if (c[j] < c[min_idx])
        min_idx = j;
 
    // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(c[min_idx], c[i]);
    }
}
//Sắp xếp chèn
void insertionSort(int c[], int n,int m,int p)
{
  p=n+m;
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = c[i];
       j = i-1;
 
       /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
       while (j >= 0 && c[j] > key)
       {
           c[j+1] = c[j];
           j = j-1;
       }
       c[j+1] = key;
   }
}
int main()
{
 int a[50],b[50],c[100],n,m,p;
 nhapmang(a,n);
 nhapmang(b,m);
 gop(a,n,b,m,c,p);
 xuatmang(c,p);
 bubbleSort(c,p,n,m);
 xuatmang(c,p);
 selectionSort(c,p,n,m);
 xuatmang(c,p);
 insertionSort(c,p,n,m);
 xuatmang(c,p);
 system("pause");
 return 0;
}