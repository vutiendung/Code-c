#include<iostream>
#include<chuoi.h>
#include<string.h>
#include<stdio.h>
using namespace std;

void kt(char s[])
{
    int i=0,n=re_length(s);
    char key1[]="(",key2[]=")";
    while(i<n-1)
    {
        char buf1[1],buf2[1];
        buf1[0]=(const char)s[i];
        buf2[0]=(const char)s[i+1];
        if(s[i]=='(' && s[i+1]==')')
        {
            re_delete(s,i+1);
            re_delete(s,i);
            if(i>0)
                i--;
            n=re_length(s);
        }
        else
        {
            i++;
        }
        if(i==n-1) break;
    }
    if(n==0)
    cout<<"OK";
        else
            cout<<"No!";
}
int main(void)
{
    char s[254];
    cout<<"Nhap chuoi can kiem tra: ";
    gets(s);
    kt(s);
    return 0;
}
