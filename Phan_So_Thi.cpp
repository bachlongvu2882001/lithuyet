#include<iostream>
using namespace std;
class PS{
   private:
     int ts,ms;
    public:
      PS();
      PS(int ts,int ms);
      friend ostream& operator<<(ostream &out,PS &temp);
      PS operator+(PS ps1);
      int UCLN(int a, int b);
      void RutGon();
};
PS::PS(){
    this->ts=0;
    this->ms=1;
}
PS::PS(int _ts,int _ms){
    
            ts=_ts;
            ms=_ms;
        
}
ostream& operator<<(ostream &out,PS &temp){
    if(temp.ts==0){
    out<<0;
    }
    else if(temp.ms==0)
     {
         out<<"Khong xac dinh";
         }
     else
     out<<temp.ts<<"/"<<temp.ms;
     return out;
}
int PS::UCLN(int a, int b) { 
	if (a==0 ||b==0) 
		return a+b; 
while (a !=b) { 
	if(a>b)
                    a=a-b;
                else
                    b=b-a;
            }
      return a;
       
}

PS PS:: operator+(PS ps1){
     
    PS tong;
    if(this->ts==0){
        return ps1;
    }
    else{
    tong.ts=(this->ts*ps1.ms+this->ms*ps1.ts);
    tong.ms=(this->ms*ps1.ms);
    return tong;
    }
}
void PS::RutGon()
{
    int iUCLN = UCLN(ts,ms);
    ts = ts / iUCLN;
    ms = ms / iUCLN;
}
int main(){
    PS d,b,c;
    c=d+b;
    cout<<"\nPhan so thu 1: "<<d<<endl;
     cout<<"\nPhan so thu 2: "<<b<<endl;
     c.RutGon();
    cout<<"cong phan so: "<<c<<endl;
    system("pause");
    return 0;
}