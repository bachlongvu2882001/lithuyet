#include <iostream> 
using namespace std; 
class KhoangCach 
{ 
    private: 
    int met; 
    int centimet; 
    public: 
    // phan khai bao cac constructor can thiet 
    KhoangCach()
    { 
        met = 0; 
        centimet = 0; 
    } 
    KhoangCach(int m, int c)
    { 
        met = m; 
        centimet = c; 
    } 
    void operator=( KhoangCach &K) 
    { 
        met = K.met; 
        centimet = K.centimet; 
    } 
    // phuong thuc de hien thi khoang cach 
    void hienthiKC() 
    { 
        cout << "\nDo dai bang m la: " << met << "\nVa do dai bang cm la: " << centimet << endl; 
    } 
}; 
int main() 
{ 
    KhoangCach K1(23, 16), K2(15, 46); 
    cout << "Khoang cach dau tien: "; 
    K1.hienthiKC(); 
    cout << "\n-------------------\n"; 
    cout << "Khoang cach thu hai:"; 
    K2.hienthiKC(); 
    // su dung toan tu gan 
    K1 = K2; 
    cout << "\n-------------------\n"; 
    cout << "Khoang cach dau tien: "; 
    K1.hienthiKC(); 
    system("pause");
    return 0; 
}