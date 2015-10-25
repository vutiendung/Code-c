#include<iostream>
#include <fstream>
#include<math.h>
using namespace std;
struct Object
{
  int Data[50][50];
  int Class;
};
int KhoangCach(Object a,Object b,int m,int n)
{
    int dem=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(a.Data[i][j]==b.Data[i][j] && a.Data[i][j]==1)
                dem++;
    return m*n-dem;
}
int main()
{
    //khai bao
    Object a[100];
    Object _obj;
    int soLuong;
    int k;
    int m,n; //kich thuoc
    int kc[soLuong],vt[soLuong];
    ifstream _readData("C:/Data/HuanLuyen.txt");


    //doc du lieu tu file
    _readData>>soLuong;
    _readData>>m>>n;

    //xuat du lieu
    for(int d=0;d<soLuong;d++)
    {
        _readData>>a[d].Class;
        for(int i=0;i<m;i++)
        {
           _readData>>a[d].Data[i][0]>>a[d].Data[i][1]>>a[d].Data[i][2];
        }

    }
    _readData.close();

    //Xuat man hinh
    for(int d=0;d<soLuong;d++)
    {
        cout<<"--Lop:"<<a[d].Class<<endl;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                {
                    cout<<a[d].Data[i][j]<<" ";
                    if(j==n-1)
                        cout<<endl;
                }
    }

    cout<<"k=";
    cin>>k;
    cout<<"Nhap bo so can kiem tra:"<<endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
           cout<<"["<<i<<","<<j<<"]=";
           cin>>_obj.Data[i][j];
        }
    cout<<"Start";

    //Bat dau thuat toan

    //tinh khoang cach
    for(int i=0;i<soLuong;i++)
    {
        kc[i]=KhoangCach(_obj,a[i],m,n);
        vt[i]=i;
    }
    //sap xep khoang cach
    for(int i=0;i<soLuong-1;i++)
    {
        for(int j=0;j<soLuong;j++)
        {
            if(kc[i]>kc[j])
            {
                //trao doi
                int tg=kc[i];
                kc[i]=kc[j];
                kc[j]=tg;

                tg=vt[i];
                vt[i]=vt[j];
                vt[j]=tg;
            }
        }
    }

    //dem k lang gieng
    int d1=0,d0=0;
    for(int i=0;i<k;i++)
    {
        if(a[vt[i]].Class==1)
            d1++;
        else
            d0++;
    }
    if(d1>d0)
        cout<<"La bat thuong!";
    else
        cout<<"Khong la bat thuong";

    return 0;
}
