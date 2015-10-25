#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

bool IsNumBer(string a)
{
    int maAscii=(int)a;
    if(maAscii>47 && maAscii<58)
        return true;
    else
        return false;
}
int main()
{
    string s;
    cout<<"Nhap chuoi phep tinh: ";
    getline(cin,s);
    cout<<s.length();

    //khai bao
    int next=0;
    //bat dau
    for(int i=0;i<s.length();i++)
    {
        if(IsNumBer(s[i]))
            cout<<a[i];
    }
    cout<<next;
    return 0;
}
