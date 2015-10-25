#include<iostream>
#include<conio.h>
using namespace std;

int soNgayCuaThang(int nam,int thang)
{
    bool kt;
    if(nam%100==0)
        if(nam%400==0) kt=true;
        else kt=false;
    else
        if(nam%4==0) kt=true;
        else kt=false;
    if(thang==9 || thang==4 || thang==6 || thang==11)
        return 30;
    else
        if(thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10 || thang==12)
            return 31;
        else
            if(kt) return 29;
                else return 28;
}


int main()
{
    cout<<"Thong ke cac thang co thu 6 ngay 13"<<endl;
    int a[1][7];
    for(int i=0;i<=5;i++)
        a[0][i]=0;
   cout<<"Nhap So luong nam: ";
   int n;
   cin>>n;
   int ngay=1,thang=1,nam=1900,thu=2;
   int k=nam+n;

   while(nam<=k)
   {
        while(thang<=12)
        {
            while(ngay<=soNgayCuaThang(nam,thang))
            {
               if(ngay==13 && thu==6)
               {
                   a[0][thu-2]+=1;
                   cout<<"\tThang: "<<thang<<endl;
               }
                if(thu<=7)
                    thu++;
                    else
                    thu=2;
                ngay++;
            }
            if(ngay=soNgayCuaThang(nam,thang)+1 && thang<12)
            {
                ngay=1;
            }
            if(thang==12 && ngay==32)
            {
                ngay=1;
                thang=0;
            }
            thang++;

        }
        if(thang==13)
        {
            thang=1;
            ngay=1;
        }
        nam++;
        cout<<"Nam :"<<nam<<endl;
    }
//    for(int i=0;i<=5;i++)
//        cout<<a[0][i]<<" ";
}
