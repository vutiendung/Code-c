//#include<dos.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<chuoi.h>
using namespace std;

int main()
{
    char s[254];
    cout<<"Comand Dos [Version 6.1.7601]"<<endl;
    cout<<"Copyright (c) 2014 Tien Dung Corporation.  All rights reserved."<<endl<<endl;
    while(true)
    {

        fflush(stdin);
        gets(s);
        if(re_strcmp(s,"exit")==true || re_strcmp(s,"thoat")==true) break;
        if(re_strcmp(s,"xem ping")==true)
        {
            system("ping google.com -t");
            cout<<endl;
        }
        if(re_strcmp(s,"xem ip")==true)
        {
            system("ipconfig/all");
            cout<<endl;
        }
        if(re_strcmp(s,"xem netcut")==true)
        {
            system("arp -a");
        }
        if(re_strcmp(s,"tat may")==true)
        {
            system("shutdown -s -p");
        }
         if(re_strcmp(s,"tro giup")==true)
        {
            cout<<"Lenh\tMo ta"<<endl;
            cout<<"Xoa man hinh"<<endl;
            cout<<"Tro giup";

        }
        else
            system(s);
    }
    return 0;
}
