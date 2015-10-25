//sap xep ky tu ben trong tu
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;
int re_length(char s[254])
{
    int leng=0;
    while(s[leng]!='\0')
    {
        ++leng;
    }
    return leng;
}
void re_delete(char s[254],int vt)
{
    for(int i=vt;i<=re_length(s);i++)
        s[i]=s[i+1];
    s[re_length(s)]='\0';
}
void re_trim(char s[254])
{
    while(s[0]==' ')
    {
       if(s[0]==' ')
        {
            re_delete(s,0);
        }
    }
    int a=re_length(s);
    while(s[a]==' ')
    {
        re_delete(s,a);
    }
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]==' ' && s[i+1]==' ')
            re_delete(s,i);
        else
            i++;
    }
}
int re_count_word(char s[254])
{
    int w=0,i=0;
    re_trim(s);
    while(s[i]!='\0')
    {
        if(s[i]==' ') w++;
        i++;
    }
    return w+1;
}
int main()
{
    char s[256];
    cout<<"Nhap chuoi s:";
    gets(s);
    int soTU=re_count_word(s);
    int j=0;
    while(s[j]!='\0')
    {
        int start=j,end;
        while(s[j]!=' ' && s[j]!='\0')
        {
            j++;
        }
        end=j-1;
        j++;
        for(int m=start;m<end;m++)
            for(int n=m+1;n<=end;n++)
                if(int(s[m])>int(s[n]))
                    {
                        char tg[1];
                        tg[0]=s[m];
                        s[m]=s[n];
                        s[n]=tg[0];
                    }
    }
    cout<<"Chuoi sau khi sap xep: "<<s;
    return 0;
}
