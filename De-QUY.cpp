#include<iostream>
using namespace std;
float dequy(float a[],int n);
int main(){
    float arr[]={1,2,3,4,5};
    float x=6;
    float b[5];
    int z =0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<6;j++){
        if(arr[i]+arr[j]==x){
            b[z] = arr[i];
            cout<<b[z]<<endl;
            z++;
            b[z] = arr[j];
            cout<<b[z]<<endl;
            z++;
        }
        }
    }
    cout<<"Cac tap thoa man dk: ";
    for(int i=0; i<5; i++){
        if((b[i]+b[i+1])==6){
        cout<<"A"<<i+1<<" = {"<<b[i]<<" , "<<b[i+1]<<"}";
       
        cout<<endl;
        } 
    }
     system("pause");
}
// float dequy(float a[],int  n) {
    
//     if(a)

// }
// #include <iostream>

// using namespace std;

// int sum(int n,int x) {
//     if (n == 0) return 0;
//     if ( == x) {
//         return sum(n - 1 ,x);
//     } else {
//         return n + sum(n - 1 ,x);
//     }
// }

// int main() {

//     int arr[]={ };
//     int x;
//     cin >> n>>x;
//     cout << sum(n, x);
//     system("pause");
//     return 0;
// }