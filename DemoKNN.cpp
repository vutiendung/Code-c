#include<iostream>
#include <fstream>
#include<math.h>
using namespace std;
struct Point
{
    int X,Y;
    char _class[1];
};
int main()
{
    cout<<"Thuat toan KNN!"<<endl;
    Point Data[50];
    ifstream _readData ("C:/Data/Data.txt");
    int count;
    _readData>>count;
    for(int i=0;i<count;i++)
    {
        _readData>>Data[i].X;
        _readData>>Data[i].Y;
        _readData>>Data[i]._class[0];
    }
    _readData.close();
    cout<<"Nhap bo so can kiem tra:"<<endl;
    int x,y,k;
    cout<<"   X:=";
    cin>>x;
    cout<<"   Y:=";
    cin>>y;
    cout<<"So  lang gieng k:=";
    cin>>k;
    float kc[count];
    int vitri[count];
    int n[k];

    //Tinh khoang cach
    for(int i=0;i<count;i++)
    {
        kc[i]=double(sqrt((Data[i].X-x)*(Data[i].X-x) + (Data[i].Y-y)*(Data[i].Y-y)));
        vitri[i]=i;
    }

    //sap xep khoang cach
    for(int i=0;i<count-1;i++)
        for(int j=i;j<count;j++)
        {
            if(kc[i]>kc[j])
            {
                double tg=kc[i];
                kc[i]=kc[j];
                kc[j]=tg;

                int _tg=vitri[i];
                vitri[i]=vitri[j];
                vitri[j]=tg;
            }
        }
    int cout1=0,cout0=0;
    //dem so thuoc lop + hay -
    for(int i=0;i<k;i++)
    {
        if(Data[vitri[i]]._class[0]=='+')
            cout1++;
            else
                cout0++;
    }
    if(cout0==cout1)
        cout<<"Khong phan duoc cum!";
        else
        if(cout1>cout0)
            cout<<"Phan vao lop + !";
            else
                cout<<"Phan vao lop - !";
    return 0;
}
