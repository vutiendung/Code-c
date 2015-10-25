#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;
//lay do dai xau ky tu
int re_length(char s[254])
{
    int leng=0;
    while(s[leng]!='\0')
    {
        ++leng;
    }
    return leng;
}
//so sanh chuoi
bool re_strcmp(char s1[254],char s2[245])
{

    if(re_length(s1)!=re_length(s2)) return false;
    else
    {
        int i=re_length(s1),j=0;
        while(j<i)
        {
            if(s1[j]!=s2[j]) return false;
            ++j;
        }
        return true;
    }
}
//xoa ki tu tai vi tri vt
void re_delete(char s[254],int vt)
{
    for(int i=vt;i<=re_length(s);i++)
        s[i]=s[i+1];
    s[re_length(s)]='\0';
}
//chen ky tu x vao vi tri vt
void re_insert(char s[254],int vt,char x[1])
{
    for(int i=re_length(s)+1;i>vt;i--)
        s[i]=s[i-1];
    s[vt]=x[0];
}
//tra ve ky tu viet hoa
void re_topper(char s[254])
{
    int a,i=0;
    while(s[i]!='\0')
    {
        a=int(s[i]);
       if(a>=97) s[i]=char(a-32);
       i++;
    }
}
//tra ve ky tu thuong
void re_tolower(char s[254])
{
    int a,i=0;
    while(s[i]!='\0')
    {
        a=int(s[i]);
       if(a<97) s[i]=char(a+32);
       i++;
    }
}
//xoa khoang trang thua o trong chuoi
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

int re_pos(char s[254],char a[254])
{
    int i=0,h=re_length(a),j,hs=re_length(s),d=0;
    for(i=0;i<hs-h+1;i++)
    {
        for(j=i;j<=i+h-1;j++)
            if(s[j]!=a[j-i])
                break;
            else d++;
        if(d==h) return i;
    }
}

void re_copy(char s[254],int vt,char b[254])
{
    int i=vt,h=re_length(s);
    int k=h-vt-1;
    while(s[i]!='\0')
    {
        b[i-k]+=s[i];
        i++;
    }
}
//chuyen chuoi ve so
long re_convert_toLong(char s[254])
{
    long k=re_length(s),i=0,d=0,tg;
    long end=0;
    while(s[i]!='\0')
    {
        long a=long(s[i]);
        if(a>=48 && a<=57)
        {
           tg=a-48;
            end=end*10+tg;
            d++;
        }
        i++;
    }
    return end;
}
//chuyen so ve ky tu
char re_convert_toChar(int a)
{
    return char(a+48);
}
//dem so tu trong cau
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

